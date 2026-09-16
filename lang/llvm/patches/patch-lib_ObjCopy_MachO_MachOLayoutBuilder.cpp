$NetBSD: patch-lib_ObjCopy_MachO_MachOLayoutBuilder.cpp,v 1.1 2026/09/16 11:00:39 tnn Exp $

Fix llvm-objcopy producing mis-aligned __LINKEDIT segment.
ld on xcode 27 rejects such dylibs. This breaks notably rustc.
Patch via https://github.com/llvm/llvm-project/pull/203680

--- lib/ObjCopy/MachO/MachOLayoutBuilder.cpp.orig	2025-12-12 10:35:47.000000000 +0000
+++ lib/ObjCopy/MachO/MachOLayoutBuilder.cpp
@@ -236,24 +236,27 @@
          "Incorrect tail offset");
   Offset = std::max(Offset, HeaderSize + O.Header.SizeOfCmds);
 
+  const uint64_t LinkEditAlign = Is64Bit ? 8 : 4;
+  Offset = alignToPowerOf2(Offset, LinkEditAlign);
+
   // The exports trie can be in either LC_DYLD_INFO or in
   // LC_DYLD_EXPORTS_TRIE, but not both.
-  size_t DyldInfoExportsTrieSize = 0;
-  size_t DyldExportsTrieSize = 0;
+  uint64_t DyldInfoExportsTrieRawSize = 0;
+  uint64_t DyldExportsTrieRawSize = 0;
   for (const auto &LC : O.LoadCommands) {
     switch (LC.MachOLoadCommand.load_command_data.cmd) {
     case MachO::LC_DYLD_INFO:
     case MachO::LC_DYLD_INFO_ONLY:
-      DyldInfoExportsTrieSize = O.Exports.Trie.size();
+      DyldInfoExportsTrieRawSize = O.Exports.Trie.size();
       break;
     case MachO::LC_DYLD_EXPORTS_TRIE:
-      DyldExportsTrieSize = O.Exports.Trie.size();
+      DyldExportsTrieRawSize = O.Exports.Trie.size();
       break;
     default:
       break;
     }
   }
-  assert((DyldInfoExportsTrieSize == 0 || DyldExportsTrieSize == 0) &&
+  assert((DyldInfoExportsTrieRawSize == 0 || DyldExportsTrieRawSize == 0) &&
          "Export trie in both LCs");
 
   uint64_t NListSize = Is64Bit ? sizeof(MachO::nlist_64) : sizeof(MachO::nlist);
@@ -264,28 +267,43 @@
   // trie, chained fixups, dyld exports trie, function starts, data-in-code,
   // symbol table, indirect symbol table, symbol table strings,
   // dylib codesign drs, and code signature.
-  auto updateOffset = [&Offset](size_t Size) {
+  auto updateOffset = [&Offset, LinkEditAlign](uint64_t Size) {
     uint64_t PreviousOffset = Offset;
-    Offset += Size;
-    return PreviousOffset;
+    // Match ld64 and lld-macho behavior by aligning all LINKEDIT entries to
+    // pointer size. This is safe because zero padding is valid for all entries.
+    uint64_t PaddedSize = alignToPowerOf2(Size, LinkEditAlign);
+    Offset += PaddedSize;
+    return std::make_pair(PreviousOffset, PaddedSize);
   };
 
-  uint64_t StartOfRebaseInfo = updateOffset(O.Rebases.Opcodes.size());
-  uint64_t StartOfBindingInfo = updateOffset(O.Binds.Opcodes.size());
-  uint64_t StartOfWeakBindingInfo = updateOffset(O.WeakBinds.Opcodes.size());
-  uint64_t StartOfLazyBindingInfo = updateOffset(O.LazyBinds.Opcodes.size());
-  uint64_t StartOfExportTrie = updateOffset(DyldInfoExportsTrieSize);
-  uint64_t StartOfChainedFixups = updateOffset(O.ChainedFixups.Data.size());
-  uint64_t StartOfDyldExportsTrie = updateOffset(DyldExportsTrieSize);
-  uint64_t StartOfFunctionStarts = updateOffset(O.FunctionStarts.Data.size());
-  uint64_t StartOfDataInCode = updateOffset(O.DataInCode.Data.size());
-  uint64_t StartOfLinkerOptimizationHint =
-      updateOffset(O.LinkerOptimizationHint.Data.size());
-  uint64_t StartOfSymbols = updateOffset(NListSize * O.SymTable.Symbols.size());
+  auto [StartOfRebaseInfo, RebaseInfoSize] =
+      updateOffset(O.Rebases.Opcodes.size());
+  auto [StartOfBindingInfo, BindingInfoSize] =
+      updateOffset(O.Binds.Opcodes.size());
+  auto [StartOfWeakBindingInfo, WeakBindingInfoSize] =
+      updateOffset(O.WeakBinds.Opcodes.size());
+  auto [StartOfLazyBindingInfo, LazyBindingInfoSize] =
+      updateOffset(O.LazyBinds.Opcodes.size());
+  auto [StartOfExportTrie, ExportTrieSize] =
+      updateOffset(DyldInfoExportsTrieRawSize);
+  auto [StartOfChainedFixups, ChainedFixupsSize] =
+      updateOffset(O.ChainedFixups.Data.size());
+  auto [StartOfDyldExportsTrie, DyldExportsTrieSize] =
+      updateOffset(DyldExportsTrieRawSize);
+  auto [StartOfFunctionStarts, FunctionStartsSize] =
+      updateOffset(O.FunctionStarts.Data.size());
+  auto [StartOfDataInCode, DataInCodeSize] =
+      updateOffset(O.DataInCode.Data.size());
+  auto [StartOfLinkerOptimizationHint, LinkerOptimizationHintSize] =
+      updateOffset(O.LinkerOptimizationHint.Data.size());
+  uint64_t StartOfSymbols =
+      updateOffset(NListSize * O.SymTable.Symbols.size()).first;
   uint64_t StartOfIndirectSymbols =
-      updateOffset(sizeof(uint32_t) * O.IndirectSymTable.Symbols.size());
-  uint64_t StartOfSymbolStrings = updateOffset(StrTableBuilder.getSize());
-  uint64_t StartOfDylibCodeSignDRs = updateOffset(O.DylibCodeSignDRs.Data.size());
+      updateOffset(sizeof(uint32_t) * O.IndirectSymTable.Symbols.size()).first;
+  auto [StartOfSymbolStrings, SymbolStringsSize] =
+      updateOffset(StrTableBuilder.getSize());
+  auto [StartOfDylibCodeSignDRs, DylibCodeSignDRsSize] =
+      updateOffset(O.DylibCodeSignDRs.Data.size());
 
   uint64_t StartOfCodeSignature = Offset;
   uint32_t CodeSignatureSize = 0;
@@ -344,13 +362,13 @@
       break;
     case MachO::LC_DYLIB_CODE_SIGN_DRS:
       MLC.linkedit_data_command_data.dataoff = StartOfDylibCodeSignDRs;
-      MLC.linkedit_data_command_data.datasize = O.DylibCodeSignDRs.Data.size();
+      MLC.linkedit_data_command_data.datasize = DylibCodeSignDRsSize;
       break;
     case MachO::LC_SYMTAB:
       MLC.symtab_command_data.symoff = StartOfSymbols;
       MLC.symtab_command_data.nsyms = O.SymTable.Symbols.size();
       MLC.symtab_command_data.stroff = StartOfSymbolStrings;
-      MLC.symtab_command_data.strsize = StrTableBuilder.getSize();
+      MLC.symtab_command_data.strsize = SymbolStringsSize;
       break;
     case MachO::LC_DYSYMTAB: {
       if (MLC.dysymtab_command_data.ntoc != 0 ||
@@ -369,20 +387,19 @@
     }
     case MachO::LC_DATA_IN_CODE:
       MLC.linkedit_data_command_data.dataoff = StartOfDataInCode;
-      MLC.linkedit_data_command_data.datasize = O.DataInCode.Data.size();
+      MLC.linkedit_data_command_data.datasize = DataInCodeSize;
       break;
     case MachO::LC_LINKER_OPTIMIZATION_HINT:
       MLC.linkedit_data_command_data.dataoff = StartOfLinkerOptimizationHint;
-      MLC.linkedit_data_command_data.datasize =
-          O.LinkerOptimizationHint.Data.size();
+      MLC.linkedit_data_command_data.datasize = LinkerOptimizationHintSize;
       break;
     case MachO::LC_FUNCTION_STARTS:
       MLC.linkedit_data_command_data.dataoff = StartOfFunctionStarts;
-      MLC.linkedit_data_command_data.datasize = O.FunctionStarts.Data.size();
+      MLC.linkedit_data_command_data.datasize = FunctionStartsSize;
       break;
     case MachO::LC_DYLD_CHAINED_FIXUPS:
       MLC.linkedit_data_command_data.dataoff = StartOfChainedFixups;
-      MLC.linkedit_data_command_data.datasize = O.ChainedFixups.Data.size();
+      MLC.linkedit_data_command_data.datasize = ChainedFixupsSize;
       break;
     case MachO::LC_DYLD_EXPORTS_TRIE:
       MLC.linkedit_data_command_data.dataoff = StartOfDyldExportsTrie;
@@ -392,19 +409,19 @@
     case MachO::LC_DYLD_INFO_ONLY:
       MLC.dyld_info_command_data.rebase_off =
           O.Rebases.Opcodes.empty() ? 0 : StartOfRebaseInfo;
-      MLC.dyld_info_command_data.rebase_size = O.Rebases.Opcodes.size();
+      MLC.dyld_info_command_data.rebase_size = RebaseInfoSize;
       MLC.dyld_info_command_data.bind_off =
           O.Binds.Opcodes.empty() ? 0 : StartOfBindingInfo;
-      MLC.dyld_info_command_data.bind_size = O.Binds.Opcodes.size();
+      MLC.dyld_info_command_data.bind_size = BindingInfoSize;
       MLC.dyld_info_command_data.weak_bind_off =
           O.WeakBinds.Opcodes.empty() ? 0 : StartOfWeakBindingInfo;
-      MLC.dyld_info_command_data.weak_bind_size = O.WeakBinds.Opcodes.size();
+      MLC.dyld_info_command_data.weak_bind_size = WeakBindingInfoSize;
       MLC.dyld_info_command_data.lazy_bind_off =
           O.LazyBinds.Opcodes.empty() ? 0 : StartOfLazyBindingInfo;
-      MLC.dyld_info_command_data.lazy_bind_size = O.LazyBinds.Opcodes.size();
+      MLC.dyld_info_command_data.lazy_bind_size = LazyBindingInfoSize;
       MLC.dyld_info_command_data.export_off =
           O.Exports.Trie.empty() ? 0 : StartOfExportTrie;
-      MLC.dyld_info_command_data.export_size = DyldInfoExportsTrieSize;
+      MLC.dyld_info_command_data.export_size = ExportTrieSize;
       break;
     // Note that LC_ENCRYPTION_INFO.cryptoff despite its name and the comment in
     // <mach-o/loader.h> is not an offset in the binary file, instead, it is a
