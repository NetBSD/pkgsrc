$NetBSD: patch-src_tapedd.c,v 1.1 2013/10/20 18:11:20 joerg Exp $

--- src/tapedd.c.orig	2013-10-18 22:47:55.000000000 +0000
+++ src/tapedd.c
@@ -243,6 +243,7 @@ long sw_recskip = 0;
 long sw_fileskip = 0;
 rsiz_t sw_bothsiz = 0;
 char *sw_logpath = NULL;
+#define logf my_logf
 FILE *logf = NULL;
 
 struct dev {
