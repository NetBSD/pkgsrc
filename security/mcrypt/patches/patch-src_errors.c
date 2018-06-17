$NetBSD: patch-src_errors.c,v 1.1.2.2 2018/06/17 11:40:03 spz Exp $

* Fix potential format-string attacks via filename arguments and
  possibly others. (No vulnerability Id)
       
  From: Debian, Red Hat, SUSE

--- src/errors.c.orig	2007-11-07 17:10:19.000000000 +0000
+++ src/errors.c
@@ -24,24 +24,24 @@ extern int quiet;
 
 void err_quit(char *errmsg)
 {
-	fprintf(stderr, errmsg);
+	fprintf(stderr, "%s", errmsg);
 	exit(-1);
 }
 
 void err_warn(char *errmsg)
 {
 	if (quiet <= 1)
-		fprintf(stderr, errmsg);
+		fprintf(stderr, "%s", errmsg);
 }
 
 void err_info(char *errmsg)
 {
 	if (quiet == 0)
-		fprintf(stderr, errmsg);
+		fprintf(stderr, "%s", errmsg);
 }
 
 void err_crit(char *errmsg)
 {
 	if (quiet <= 2)
-		fprintf(stderr, errmsg);
+		fprintf(stderr, "%s", errmsg);
 }
