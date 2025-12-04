$NetBSD: patch-absl_debugging_internal_elf__mem__image.cc,v 1.6 2025/12/04 15:37:41 ryoon Exp $

NetBSD 9 does not have DT_GNU_HASH

NetBSD 11.99.4 or later, definitions for ELF have changed.

--- absl/debugging/internal/elf_mem_image.cc.orig	2025-09-22 18:24:38.000000000 +0000
+++ absl/debugging/internal/elf_mem_image.cc
@@ -225,9 +225,11 @@ void ElfMemImage::Init(const void *base)
       case DT_HASH:
         sysv_hash = reinterpret_cast<uint32_t *>(value);
         break;
+#ifdef DT_GNU_HASH
       case DT_GNU_HASH:
         gnu_hash = reinterpret_cast<uint32_t *>(value);
         break;
+#endif
       case DT_SYMTAB:
         dynsym_ = reinterpret_cast<ElfW(Sym) *>(value);
         break;
@@ -377,7 +379,7 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && ((_SYS_EXEC_ELF_H_ + 0) < 2)
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
