$NetBSD: patch-deps_v8_third__party_abseil-cpp_absl_debugging_internal_elf__mem__image.cc,v 1.4 2026/03/04 07:04:23 adam Exp $

Fix build on NetBSD.

--- deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc.orig	2026-03-03 01:28:34.000000000 +0000
+++ deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc
@@ -377,7 +377,7 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && ((_SYS_EXEC_ELF_H_ + 0) < 2)
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
