$NetBSD: patch-httpd.c,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- httpd.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ httpd.c
@@ -1,3 +1,4 @@
+#include <sys/socket.h>
 #include "pathdecode.h"
 #include "file.h"
 #include "filetype.h"
@@ -15,6 +16,7 @@
 #include "substdio.h"
 #include "error.h"
 #include "getln.h"
+#include "byte.h"
 
 int safewrite(int fd,char *buf,int len)
 {
@@ -209,7 +211,7 @@ void readline(void)
   if (line.len && (line.s[line.len - 1] == '\r')) --line.len;
 }
 
-void doit()
+void doit(void)
 {
   int i;
   int spaces;
