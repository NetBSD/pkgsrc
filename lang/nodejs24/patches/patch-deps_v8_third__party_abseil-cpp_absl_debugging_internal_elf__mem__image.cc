$NetBSD: patch-deps_v8_third__party_abseil-cpp_absl_debugging_internal_elf__mem__image.cc,v 1.2 2025/11/16 17:43:20 wiz Exp $

Fix build on NetBSD.

--- deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc.orig	2025-11-11 13:52:04.000000000 +0000
+++ deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc
@@ -25,6 +25,10 @@
 #include <cstddef>
 #include <cstdint>
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 #include "absl/base/config.h"
 #include "absl/base/internal/raw_logging.h"
 
@@ -377,7 +381,7 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 1199000400)
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
