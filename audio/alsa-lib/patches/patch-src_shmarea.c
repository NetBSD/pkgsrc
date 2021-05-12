$NetBSD: patch-src_shmarea.c,v 1.3 2021/05/12 14:12:13 ryoon Exp $

--- src/shmarea.c.orig	2020-06-29 10:51:08.000000000 +0000
+++ src/shmarea.c
@@ -24,7 +24,7 @@
 #ifdef HAVE_SYS_SHM_H
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <poll.h>
