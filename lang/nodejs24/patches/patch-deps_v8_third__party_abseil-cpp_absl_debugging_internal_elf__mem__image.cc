$NetBSD: patch-deps_v8_third__party_abseil-cpp_absl_debugging_internal_elf__mem__image.cc,v 1.1 2025/11/13 19:00:13 adam Exp $

Fix build on NetBSD.

--- deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc.orig	2025-11-13 13:08:23.508427916 +0000
+++ deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc
@@ -377,11 +377,7 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
-  const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
-#else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
-#endif
   const ElfW(Verdef) *version_definition = nullptr;
   const char *version_name = "";
   if (symbol->st_shndx == SHN_UNDEF) {
