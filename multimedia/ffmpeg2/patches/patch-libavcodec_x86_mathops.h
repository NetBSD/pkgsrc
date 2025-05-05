$NetBSD: patch-libavcodec_x86_mathops.h,v 1.1 2025/05/05 22:47:41 wiz Exp $

Use code from ffmpeg 3.4.13 to fix build on NetBSD 10.99.14/x86_64.

--- libavcodec/x86/mathops.h.orig	2025-05-05 22:42:27.968117892 +0000
+++ libavcodec/x86/mathops.h
@@ -113,19 +113,31 @@ __asm__ volatile(\
 // avoid +32 for shift optimization (gcc should do that ...)
 #define NEG_SSR32 NEG_SSR32
 static inline  int32_t NEG_SSR32( int32_t a, int8_t s){
+    if (__builtin_constant_p(s))
     __asm__ ("sarl %1, %0\n\t"
          : "+r" (a)
-         : "ic" ((uint8_t)(-s))
+         : "i" (-s & 0x1F)
     );
+    else
+        __asm__ ("sarl %1, %0\n\t"
+               : "+r" (a)
+               : "c" ((uint8_t)(-s))
+        );
     return a;
 }
 
 #define NEG_USR32 NEG_USR32
 static inline uint32_t NEG_USR32(uint32_t a, int8_t s){
+    if (__builtin_constant_p(s))
     __asm__ ("shrl %1, %0\n\t"
          : "+r" (a)
-         : "ic" ((uint8_t)(-s))
+         : "i" (-s & 0x1F)
     );
+    else
+        __asm__ ("shrl %1, %0\n\t"
+               : "+r" (a)
+               : "c" ((uint8_t)(-s))
+        );
     return a;
 }
 
