$NetBSD: patch-sub_osd.c,v 1.3 2015/11/21 09:47:23 leot Exp $

XXX: OS X support

--- sub/osd.c.orig	2012-09-02 21:17:03.000000000 +0000
+++ sub/osd.c
@@ -31,6 +31,11 @@
 #include "libmpcodecs/img_format.h"
 #include "cpudetect.h"
 
+#if ARCH_X86 && defined(__APPLE__)
+#undef ARCH_X86
+#define ARCH_X86 0
+#endif
+
 #if ARCH_X86
 static const uint64_t bFF __attribute__((aligned(8))) = 0xFFFFFFFFFFFFFFFFULL;
 static const unsigned long long mask24lh  __attribute__((aligned(8))) = 0xFFFF000000000000ULL;
