$NetBSD: patch-src_shmarea.c,v 1.2 2016/02/18 15:15:57 wiz Exp $

--- src/shmarea.c.orig	2015-11-09 07:39:18.000000000 +0000
+++ src/shmarea.c
@@ -24,7 +24,7 @@
 #ifdef HAVE_SYS_SHM_H
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <sys/poll.h>
