$NetBSD: patch-grub-core_lib_xzembed_xz__dec__lzma2.c,v 1.1 2014/09/05 12:14:24 gsutre Exp $

Make -Wattributes not cause error.
Upstream commit 64463dfde40b4cf5e551899d656d3ef50b7a008a.

--- grub-core/lib/xzembed/xz_dec_lzma2.c.orig	2010-12-01 14:45:43.000000000 +0000
+++ grub-core/lib/xzembed/xz_dec_lzma2.c
@@ -24,6 +24,8 @@
 #include "xz_private.h"
 #include "xz_lzma2.h"
 
+#pragma GCC diagnostic warning "-Wattributes"
+
 /*
  * Range decoder initialization eats the first five bytes of each LZMA chunk.
  */
