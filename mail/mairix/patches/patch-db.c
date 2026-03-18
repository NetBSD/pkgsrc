$NetBSD: patch-db.c,v 1.1 2026/03/18 17:03:53 nia Exp $

Fix implicit declaration of bzero(3).

--- db.c.orig	2026-03-18 16:40:13.452142870 +0000
+++ db.c
@@ -28,6 +28,7 @@
 #include <assert.h>
 #include <sys/time.h>
 #include <unistd.h>
+#include <strings.h>
 
 struct sortable_token {/*{{{*/
   char *text;
