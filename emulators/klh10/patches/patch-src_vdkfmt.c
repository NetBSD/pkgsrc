$NetBSD: patch-src_vdkfmt.c,v 1.1 2013/10/20 18:11:20 joerg Exp $

--- src/vdkfmt.c.orig	2013-10-18 22:48:31.000000000 +0000
+++ src/vdkfmt.c
@@ -130,6 +130,7 @@ int sw_verbose;
 int sw_maxsec;
 int sw_maxfile;
 char *sw_logpath;
+#define logf my_logf
 FILE *logf;
 
 #define DBGFLG sw_verbose
