$NetBSD: patch-src_llvm-project_llvm_lib_ObjCopy_MachO_MachOWriter.cpp,v 1.1 2026/09/16 11:00:40 tnn Exp $

Fix llvm-objcopy producing mis-aligned __LINKEDIT segment.
ld on xcode 27 rejects such dylibs. This breaks notably rustc.
Patch via https://github.com/llvm/llvm-project/pull/203680

--- src/llvm-project/llvm/lib/ObjCopy/MachO/MachOWriter.cpp.orig	2026-06-26 21:46:14.000000000 +0000
+++ src/llvm-project/llvm/lib/ObjCopy/MachO/MachOWriter.cpp
@@ -24,6 +24,12 @@
 using namespace llvm::objcopy::macho;
 using namespace llvm::support::endian;
 
+#ifndef NDEBUG
+static uint64_t paddedLinkEditEntrySize(uint64_t Size, bool Is64Bit) {
+  return alignToPowerOf2(Size, Is64Bit ? 8 : 4);
+}
+#endif
+
 size_t MachOWriter::headerSize() const {
   return Is64Bit ? sizeof(MachO::mach_header_64) : sizeof(MachO::mach_header);
 }
@@ -55,29 +61,34 @@
         O.LoadCommands[*O.DyLdInfoCommandIndex]
             .MachOLoadCommand.dyld_info_command_data;
     if (DyLdInfoCommand.rebase_off) {
-      assert((DyLdInfoCommand.rebase_size == O.Rebases.Opcodes.size()) &&
+      assert((DyLdInfoCommand.rebase_size ==
+              paddedLinkEditEntrySize(O.Rebases.Opcodes.size(), Is64Bit)) &&
              "Incorrect rebase opcodes size");
       Ends.push_back(DyLdInfoCommand.rebase_off + DyLdInfoCommand.rebase_size);
     }
     if (DyLdInfoCommand.bind_off) {
-      assert((DyLdInfoCommand.bind_size == O.Binds.Opcodes.size()) &&
+      assert((DyLdInfoCommand.bind_size ==
+              paddedLinkEditEntrySize(O.Binds.Opcodes.size(), Is64Bit)) &&
              "Incorrect bind opcodes size");
       Ends.push_back(DyLdInfoCommand.bind_off + DyLdInfoCommand.bind_size);
     }
     if (DyLdInfoCommand.weak_bind_off) {
-      assert((DyLdInfoCommand.weak_bind_size == O.WeakBinds.Opcodes.size()) &&
+      assert((DyLdInfoCommand.weak_bind_size ==
+              paddedLinkEditEntrySize(O.WeakBinds.Opcodes.size(), Is64Bit)) &&
              "Incorrect weak bind opcodes size");
       Ends.push_back(DyLdInfoCommand.weak_bind_off +
                      DyLdInfoCommand.weak_bind_size);
     }
     if (DyLdInfoCommand.lazy_bind_off) {
-      assert((DyLdInfoCommand.lazy_bind_size == O.LazyBinds.Opcodes.size()) &&
+      assert((DyLdInfoCommand.lazy_bind_size ==
+              paddedLinkEditEntrySize(O.LazyBinds.Opcodes.size(), Is64Bit)) &&
              "Incorrect lazy bind opcodes size");
       Ends.push_back(DyLdInfoCommand.lazy_bind_off +
                      DyLdInfoCommand.lazy_bind_size);
     }
     if (DyLdInfoCommand.export_off) {
-      assert((DyLdInfoCommand.export_size == O.Exports.Trie.size()) &&
+      assert((DyLdInfoCommand.export_size ==
+              paddedLinkEditEntrySize(O.Exports.Trie.size(), Is64Bit)) &&
              "Incorrect trie size");
       Ends.push_back(DyLdInfoCommand.export_off + DyLdInfoCommand.export_size);
     }
@@ -320,7 +331,8 @@
       O.LoadCommands[*O.DyLdInfoCommandIndex]
           .MachOLoadCommand.dyld_info_command_data;
   char *Out = Buf->getBufferStart() + DyLdInfoCommand.rebase_off;
-  assert((DyLdInfoCommand.rebase_size == O.Rebases.Opcodes.size()) &&
+  assert((DyLdInfoCommand.rebase_size ==
+          paddedLinkEditEntrySize(O.Rebases.Opcodes.size(), Is64Bit)) &&
          "Incorrect rebase opcodes size");
   memcpy(Out, O.Rebases.Opcodes.data(), O.Rebases.Opcodes.size());
 }
@@ -332,7 +344,8 @@
       O.LoadCommands[*O.DyLdInfoCommandIndex]
           .MachOLoadCommand.dyld_info_command_data;
   char *Out = Buf->getBufferStart() + DyLdInfoCommand.bind_off;
-  assert((DyLdInfoCommand.bind_size == O.Binds.Opcodes.size()) &&
+  assert((DyLdInfoCommand.bind_size ==
+          paddedLinkEditEntrySize(O.Binds.Opcodes.size(), Is64Bit)) &&
          "Incorrect bind opcodes size");
   memcpy(Out, O.Binds.Opcodes.data(), O.Binds.Opcodes.size());
 }
@@ -344,7 +357,8 @@
       O.LoadCommands[*O.DyLdInfoCommandIndex]
           .MachOLoadCommand.dyld_info_command_data;
   char *Out = Buf->getBufferStart() + DyLdInfoCommand.weak_bind_off;
-  assert((DyLdInfoCommand.weak_bind_size == O.WeakBinds.Opcodes.size()) &&
+  assert((DyLdInfoCommand.weak_bind_size ==
+          paddedLinkEditEntrySize(O.WeakBinds.Opcodes.size(), Is64Bit)) &&
          "Incorrect weak bind opcodes size");
   memcpy(Out, O.WeakBinds.Opcodes.data(), O.WeakBinds.Opcodes.size());
 }
@@ -356,7 +370,8 @@
       O.LoadCommands[*O.DyLdInfoCommandIndex]
           .MachOLoadCommand.dyld_info_command_data;
   char *Out = Buf->getBufferStart() + DyLdInfoCommand.lazy_bind_off;
-  assert((DyLdInfoCommand.lazy_bind_size == O.LazyBinds.Opcodes.size()) &&
+  assert((DyLdInfoCommand.lazy_bind_size ==
+          paddedLinkEditEntrySize(O.LazyBinds.Opcodes.size(), Is64Bit)) &&
          "Incorrect lazy bind opcodes size");
   memcpy(Out, O.LazyBinds.Opcodes.data(), O.LazyBinds.Opcodes.size());
 }
@@ -368,7 +383,8 @@
       O.LoadCommands[*O.DyLdInfoCommandIndex]
           .MachOLoadCommand.dyld_info_command_data;
   char *Out = Buf->getBufferStart() + DyLdInfoCommand.export_off;
-  assert((DyLdInfoCommand.export_size == O.Exports.Trie.size()) &&
+  assert((DyLdInfoCommand.export_size ==
+          paddedLinkEditEntrySize(O.Exports.Trie.size(), Is64Bit)) &&
          "Incorrect export trie size");
   memcpy(Out, O.Exports.Trie.data(), O.Exports.Trie.size());
 }
@@ -398,7 +414,8 @@
   const MachO::linkedit_data_command &LinkEditDataCommand =
       O.LoadCommands[*LCIndex].MachOLoadCommand.linkedit_data_command_data;
   char *Out = Buf->getBufferStart() + LinkEditDataCommand.dataoff;
-  assert((LinkEditDataCommand.datasize == LD.Data.size()) &&
+  assert((LinkEditDataCommand.datasize ==
+          paddedLinkEditEntrySize(LD.Data.size(), Is64Bit)) &&
          "Incorrect data size");
   memcpy(Out, LD.Data.data(), LD.Data.size());
 }
@@ -575,7 +592,8 @@
       O.LoadCommands[*O.ExportsTrieCommandIndex]
           .MachOLoadCommand.linkedit_data_command_data;
   char *Out = Buf->getBufferStart() + ExportsTrieCmd.dataoff;
-  assert((ExportsTrieCmd.datasize == O.Exports.Trie.size()) &&
+  assert((ExportsTrieCmd.datasize ==
+          paddedLinkEditEntrySize(O.Exports.Trie.size(), Is64Bit)) &&
          "Incorrect export trie size");
   memcpy(Out, O.Exports.Trie.data(), O.Exports.Trie.size());
 }
