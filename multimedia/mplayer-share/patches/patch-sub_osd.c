$NetBSD: patch-sub_osd.c,v 1.2 2012/06/11 21:55:34 wiz Exp $

XXX: OS X support

--- sub/osd.c.orig	2010-10-27 17:53:24.000000000 +0000
+++ sub/osd.c
@@ -29,6 +29,11 @@
 #include <inttypes.h>
 #include "cpudetect.h"
 
+#if ARCH_X86 && defined(__APPLE__)
+#undef ARCH_X86
+#define ARCH_X86 0
+#endif
+
 #if ARCH_X86
 static const uint64_t bFF __attribute__((aligned(8))) = 0xFFFFFFFFFFFFFFFFULL;
 static const unsigned long long mask24lh  __attribute__((aligned(8))) = 0xFFFF000000000000ULL;
