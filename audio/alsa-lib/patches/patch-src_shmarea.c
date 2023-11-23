$NetBSD: patch-src_shmarea.c,v 1.4 2023/11/23 16:15:04 ryoon Exp $

--- src/shmarea.c.orig	2023-05-04 07:16:16.000000000 +0000
+++ src/shmarea.c
@@ -27,6 +27,8 @@
 #include <stdlib.h>
 #if HAVE_MALLOC_H
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 #include <string.h>
 #include <errno.h>
