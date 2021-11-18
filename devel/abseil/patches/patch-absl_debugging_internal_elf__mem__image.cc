$NetBSD: patch-absl_debugging_internal_elf__mem__image.cc,v 1.1 2021/11/18 13:57:34 adam Exp $

Support NetBSD.

--- absl/debugging/internal/elf_mem_image.cc.orig	2021-11-18 09:35:34.106564193 +0000
+++ absl/debugging/internal/elf_mem_image.cc
@@ -351,7 +351,11 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
+#if defined(__NetBSD__)
+  int version_index = version_symbol->vs_vers & VERSYM_VERSION;
+#else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
+#endif
   const ElfW(Verdef) *version_definition = nullptr;
   const char *version_name = "";
   if (symbol->st_shndx == SHN_UNDEF) {
