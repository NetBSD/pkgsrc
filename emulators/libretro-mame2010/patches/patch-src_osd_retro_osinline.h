$NetBSD: patch-src_osd_retro_osinline.h,v 1.1 2021/06/19 07:23:31 nia Exp $

Use the "ARM" code as a portable fallback for other architectures.

--- src/osd/retro/osinline.h.orig	2021-06-19 06:40:29.471151424 +0000
+++ src/osd/retro/osinline.h
@@ -32,16 +32,11 @@ empty
 #define _osd_exchange64(ptr, exchange) (register INT64 ret; __asm__ __volatile__ ("1: ldarx  %[ret], 0, %[ptr]      \n""   stdcx. %[exchange], 0, %[ptr] \n""   bne-   1b                     \n": [ret]      "=&r" (ret): [ptr]      "r"   (ptr), [exchange] "r"   (exchange): "cr0"); ret)
 #define osd_exchange64 _osd_exchange64
 #endif /* __ppc64__ || __PPC64__ */
-
-#endif
-
-#if defined(ARM_ENABLED)
-
+#else
 #ifndef YieldProcessor
 #define YieldProcessor() do {} while (0)
 #define osd_yield_processor() YieldProcessor()
 #endif
-
 #endif
 
 #include "eminline.h"
