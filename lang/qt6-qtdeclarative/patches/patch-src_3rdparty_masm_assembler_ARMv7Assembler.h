$NetBSD: patch-src_3rdparty_masm_assembler_ARMv7Assembler.h,v 1.2 2026/01/28 17:10:51 adam Exp $

* use a more portable interface for GCCish compilers

--- src/3rdparty/masm/assembler/ARMv7Assembler.h.orig	2026-01-21 11:37:05.000000000 +0000
+++ src/3rdparty/masm/assembler/ARMv7Assembler.h
@@ -2381,6 +2381,8 @@ public:
 #elif OS(VXWORKS)
         ::cacheFlush(DATA_CACHE, code, size);
         ::cacheInvalidate(INSTRUCTION_CACHE, code, size);
+#elif defined(__GNUC__)
+        __builtin___clear_cache(reinterpret_cast<char *>(code), reinterpret_cast<char *>(reinterpret_cast<uintptr_t>(code) + size));
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
