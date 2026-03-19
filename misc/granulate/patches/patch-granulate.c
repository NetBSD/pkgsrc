$NetBSD: patch-granulate.c,v 1.1 2026/03/19 14:53:37 nia Exp $

Fix implicit declaration of strlen(3).

--- granulate.c.orig	2026-03-19 14:42:06.304999535 +0000
+++ granulate.c
@@ -28,6 +28,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#include <string.h>
 
 #define BUFSIZE 1024
 #define RADIX 26
