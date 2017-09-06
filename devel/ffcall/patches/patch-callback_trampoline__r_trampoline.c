$NetBSD: patch-callback_trampoline__r_trampoline.c,v 1.1 2017/09/06 08:21:00 he Exp $

Add NetBSD bits for powerpc ("rs6000").
Avoid multiple definition due to cache-rs6000 also being compiled separately.

--- callback/trampoline_r/trampoline.c.orig	2004-01-26 15:00:05.000000000 +0000
+++ callback/trampoline_r/trampoline.c
@@ -219,7 +219,9 @@ extern inline
 #include "cache-hppa.c"
 #endif
 #ifdef __rs6000__
+#ifndef __NetBSD__
 #include "cache-rs6000.c"
+#endif /* __NetBSD__ -- compiled separately from .s file, leads to multiple definition error */
 #endif
 #ifdef __convex__
 #include "cache-convex.c"
@@ -283,7 +285,7 @@ extern void __TR_clear_cache();
 #define TRAMP_LENGTH 32
 #define TRAMP_ALIGN 4
 #endif
-#ifdef __rs6000sysv4__
+#if defined(__rs6000sysv4__) || defined(__rs6000netbsd__)
 #define TRAMP_LENGTH 24
 #define TRAMP_ALIGN 4
 #endif
@@ -878,6 +880,39 @@ __TR_function alloc_trampoline_r (addres
 #define tramp_data(function)  \
   hilo(*(unsigned short *) (function + 2), *(unsigned short *) (function + 6))
 #endif
+#ifdef __rs6000netbsd__
+  /* function:
+   *    {liu|lis} 13,hi16(<data>)              3D A0 hi16(<data>)
+   *    {oril|ori} 13,13,lo16(<data>)          61 AD lo16(<data>)
+   *    {liu|lis} 0,hi16(<address>)            3C 00 hi16(<address>)
+   *    {oril|ori} 0,0,lo16(<address>)         60 00 lo16(<address>)
+   *    mtctr 0                                        7C 09 03 A6
+   *    bctr                                   4E 80 04 20
+   */
+  *(short *) (function + 0) = 0x3DA0;
+  *(short *) (function + 2) = (unsigned long) data >> 16;
+  *(short *) (function + 4) = 0x61AD;
+  *(short *) (function + 6) = (unsigned long) data & 0xffff;
+  *(short *) (function + 8) = 0x3C00;
+  *(short *) (function +10) = (unsigned long) address >> 16;
+  *(short *) (function +12) = 0x6000;
+  *(short *) (function +14) = (unsigned long) address & 0xffff;
+  *(long *)  (function +16) = 0x7C0903A6;
+  *(long *)  (function +20) = 0x4E800420;
+#define is_tramp(function)  \
+  *(unsigned short *) (function + 0) == 0x3DA0 && \
+  *(unsigned short *) (function + 4) == 0x61AD && \
+  *(unsigned short *) (function + 8) == 0x3C00 && \
+  *(unsigned short *) (function +12) == 0x6000 && \
+  *(unsigned long *)  (function +16) == 0x7C0903A6 && \
+  *(unsigned long *)  (function +20) == 0x4E800420
+#define hilo(hiword,loword)  \
+  (((unsigned long) (hiword) << 16) | (unsigned long) (loword))
+#define tramp_address(function)  \
+  hilo(*(unsigned short *) (function +10), *(unsigned short *) (function +14))
+#define tramp_data(function)  \
+  hilo(*(unsigned short *) (function + 2), *(unsigned short *) (function + 6))
+#endif
 #ifdef __rs6000aix__
   /* function:
    *    .long .tramp_r
