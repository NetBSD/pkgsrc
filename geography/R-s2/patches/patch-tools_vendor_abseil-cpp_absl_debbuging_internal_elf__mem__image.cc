$NetBSD: patch-tools_vendor_abseil-cpp_absl_debbuging_internal_elf__mem__image.cc,v 1.1 2026/06/12 13:07:51 mef Exp $

Fix for ELF header updates in NetBSD 11.

--- tools/vendor/abseil-cpp/absl/debugging/internal/elf_mem_image.cc.orig	2026-06-12 21:57:03.074022311 +0900
+++ tools/vendor/abseil-cpp/absl/debugging/internal/elf_mem_image.cc	2026-06-12 21:58:19.429281523 +0900
@@ -350,7 +350,7 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && (_SYS_EXEC_ELF_H_ + 0) < 2
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
