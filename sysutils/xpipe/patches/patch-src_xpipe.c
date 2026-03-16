$NetBSD: patch-src_xpipe.c,v 1.1 2026/03/16 14:28:03 nia Exp $

Fix implicit declaration of bzero(3).

--- src/xpipe.c.orig	2026-03-16 14:10:38.763166388 +0000
+++ src/xpipe.c
@@ -38,13 +38,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
-
-#ifdef __linux
-#  include <bsd/string.h>
-#else
-#  include <string.h>
-#endif
-
+#include <string.h>
+#include <strings.h>
 
 #define XPIPE_VERSION	"2.2"
 extern char *__progname;
