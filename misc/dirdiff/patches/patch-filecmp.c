$NetBSD: patch-filecmp.c,v 1.1 2014/01/20 19:20:08 joerg Exp $

--- filecmp.c.orig	2014-01-20 17:20:35.000000000 +0000
+++ filecmp.c
@@ -10,6 +10,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <tcl.h>
+#include <unistd.h>
 #include <sys/fcntl.h>
 
 #define BSIZE		32768
