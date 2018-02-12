$NetBSD: patch-src_clib_fam__pseudo.h,v 1.1 2018/02/12 11:03:35 dholland Exp $

Don't define own NAME_MAX.

--- src/clib/fam_pseudo.h.orig	2012-11-08 22:16:13.000000000 +0000
+++ src/clib/fam_pseudo.h
@@ -43,7 +43,10 @@
 /*
  * Maximum file name length.
  */
+#include <limits.h>
+#ifndef NAME_MAX
 #define NAME_MAX                1024
+#endif
 
 /*
  * Possible events.
