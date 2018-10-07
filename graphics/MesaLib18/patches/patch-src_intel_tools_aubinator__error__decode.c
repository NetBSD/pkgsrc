$NetBSD: patch-src_intel_tools_aubinator__error__decode.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Patch from FreeBSD ports graphics/mesa-dri 17.1.0

# expose getline in FreeBSD's stdio.h
#

--- src/intel/tools/aubinator_error_decode.c.orig	2017-05-25 07:13:13.000000000 +0000
+++ src/intel/tools/aubinator_error_decode.c
@@ -22,6 +22,9 @@
  *
  */
 
+#ifdef __FreeBSD__
+#define _WITH_GETLINE
+#endif
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
