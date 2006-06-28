$NetBSD: patch-aj,v 1.1 2006/06/28 23:13:18 dbj Exp $

--- ckuus5.c.orig	2006-06-27 19:22:53.000000000 -0400
+++ ckuus5.c	2006-06-27 19:23:30.000000000 -0400
@@ -28,6 +28,8 @@
 #include "ckcker.h"
 #include "ckuusr.h"
 
+#include <errno.h>
+
 #ifdef DCMDBUF
 char *line;                             /* Character buffer for anything */
 char *tmpbuf;
