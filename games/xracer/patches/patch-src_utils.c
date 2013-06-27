$NetBSD: patch-src_utils.c,v 1.1 2013/06/27 15:49:43 joerg Exp $

--- src/utils.c.orig	2013-06-26 22:50:54.000000000 +0000
+++ src/utils.c
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
