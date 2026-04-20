$NetBSD: patch-src_absl_debugging_internal_elf__mem__image.cc,v 1.1 2026/04/20 06:06:38 wiz Exp $

Fix for ELF header updates in NetBSD 11.

--- src/absl/debugging/internal/elf_mem_image.cc.orig	2023-11-25 15:31:07.000000000 +0000
+++ src/absl/debugging/internal/elf_mem_image.cc
@@ -351,7 +351,7 @@ void ElfMemImage::SymbolIterator::Update(int increment
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && (_SYS_EXEC_ELF_H_ + 0) < 2
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
