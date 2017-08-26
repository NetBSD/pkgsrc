$NetBSD: patch-main_command.c,v 1.1 2017/08/26 10:07:28 fhajny Exp $

O_DIRECTORY is a Linuxism and O_NOFOLLOW is a BSDism ported to Linux

--- src/main/command.c.orig	2016-09-29 15:19:48.000000000 +0000
+++ src/main/command.c
@@ -21,6 +21,16 @@
  * Copyright 2008 Alan DeKok <aland@deployingradius.com>
  */
 
+/* 
+ * Not every implementation knows what O_DIRECTORY and O_NOFOLLOW are
+ */
+#ifndef O_DIRECTORY
+#define O_DIRECTORY 0
+#endif
+#ifndef O_NOFOLLOW
+#define O_NOFOLLOW 0
+#endif
+
 #ifdef WITH_COMMAND_SOCKET
 
 #include <freeradius-devel/parser.h>
