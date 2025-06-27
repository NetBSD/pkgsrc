$NetBSD: patch-instcheck.c,v 1.1 2025/06/27 17:39:55 schmonz Exp $

Avoid "'sys_errlist' undeclared" on Illumos when in C89 mode.

--- instcheck.c.orig	2025-06-25 17:50:33.221353743 +0000
+++ instcheck.c
@@ -14,14 +14,14 @@ int man;
 static void diesys(const char* msg)
 {
   fprintf(stderr, "installer error: %s:\n  %s\n", msg,
-	  sys_errlist[errno]);
+	  strerror(errno));
   exit(1);
 }
 
 static void diefsys(const char* msg, const char* filename)
 {
   fprintf(stderr, "installer error: %s '%s':\n  %s\n", msg, filename,
-	  sys_errlist[errno]);
+	  strerror(errno));
   exit(1);
 }
 
