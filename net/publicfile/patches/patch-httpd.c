$NetBSD: patch-httpd.c,v 1.2 2023/11/16 22:55:37 schmonz Exp $

Handle request URLs with an https scheme. Look for the client IP in
SSLREMOTEIP if TCPREMOTEIP is not set.
<http://www.superscript.com/patches/publicfile.sslserver>

Add missing includes.

--- httpd.c.orig	2023-11-16 22:51:58.966819579 +0000
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
@@ -271,8 +273,16 @@ void doit()
       if (!stralloc_copyb(&path,host.s + i,host.len - i)) _exit(21);
       host.len = i;
     }
-    else
-      if (!stralloc_copy(&path,&url)) _exit(21);
+    else {
+      if (case_startb(url.s,url.len,"https://")) {
+	if (!stralloc_copyb(&host,url.s + 8,url.len - 8)) _exit(21);
+	i = byte_chr(host.s,host.len,'/');
+	if (!stralloc_copyb(&path,host.s + i,host.len - i)) _exit(21);
+	host.len = i;
+      }
+      else
+	if (!stralloc_copy(&path,&url)) _exit(21);
+    }
 
     if (!path.len || (path.s[path.len - 1] == '/'))
       if (!stralloc_cats(&path,"index.html")) _exit(21);
