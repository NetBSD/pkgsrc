$NetBSD: patch-src_shmarea.c,v 1.1 2014/03/25 23:06:07 asau Exp $

--- src/shmarea.c.orig	2009-12-16 15:18:51.000000000 +0000
+++ src/shmarea.c
@@ -19,7 +19,7 @@
  */
   
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <sys/poll.h>
