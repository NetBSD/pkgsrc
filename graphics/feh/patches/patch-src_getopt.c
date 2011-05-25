$NetBSD: patch-src_getopt.c,v 1.1 2011/05/25 19:44:27 gls Exp $

--- src/getopt.c.orig	2011-05-19 20:36:13.000000000 +0000
+++ src/getopt.c
@@ -36,6 +36,7 @@
 #endif
 
 #include <stdio.h>
+#include <string.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C
