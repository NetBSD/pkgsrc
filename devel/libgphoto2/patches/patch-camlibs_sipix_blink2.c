$NetBSD: patch-camlibs_sipix_blink2.c,v 1.1 2022/04/25 22:23:00 tnn Exp $

#include <limits.h> for UINT_MAX

--- camlibs/sipix/blink2.c.orig	2020-08-28 14:16:06.000000000 +0000
+++ camlibs/sipix/blink2.c
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>
 
 #ifdef HAVE_LIBJPEG
 # include <jpeglib.h>
