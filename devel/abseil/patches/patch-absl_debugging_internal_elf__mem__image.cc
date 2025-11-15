$NetBSD: patch-absl_debugging_internal_elf__mem__image.cc,v 1.5 2025/11/15 11:51:58 ryoon Exp $

NetBSD 9 does not have DT_GNU_HASH

NetBSD 11.99.4 or later, definitions for ELF have changed.

--- absl/debugging/internal/elf_mem_image.cc.orig	2025-09-22 18:24:38.000000000 +0000
+++ absl/debugging/internal/elf_mem_image.cc
@@ -25,6 +25,10 @@
 #include <cstddef>
 #include <cstdint>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #include "absl/base/config.h"
 #include "absl/base/internal/raw_logging.h"
 
@@ -225,9 +229,11 @@ void ElfMemImage::Init(const void *base)
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
@@ -377,7 +383,7 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && __NetBSD_Version__ < 1199000400
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
