$NetBSD: patch-file.c,v 1.2 2023/11/16 22:55:37 schmonz Exp $

Handle request URLs with an https scheme. Look for the client IP in
SSLREMOTEIP if TCPREMOTEIP is not set.
<http://www.superscript.com/patches/publicfile.sslserver>

Add missing includes.

--- file.c.orig	2023-11-16 22:52:07.122614429 +0000
+++ file.c
@@ -7,6 +7,8 @@
 #include "str.h"
 #include "tai.h"
 #include "env.h"
+#include "open.h"
+#include "exit.h"
 
 static void log(char *fn,char *result1,char *result2,int flagread)
 {
@@ -15,7 +17,11 @@ static void log(char *fn,char *result1,c
   char *x;
 
   x = env_get("TCPREMOTEIP");
-  if (!x) x = "0";
+  if (!x) {
+    x = env_get("SSLREMOTEIP");
+    if (!x)
+      x = "0";
+  }
   substdio_puts(subfderr,x);
   substdio_puts(subfderr,flagread ? " read ": " dir ");
 
