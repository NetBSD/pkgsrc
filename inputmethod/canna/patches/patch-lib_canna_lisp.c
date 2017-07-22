$NetBSD: patch-lib_canna_lisp.c,v 1.1 2017/07/22 17:44:40 maya Exp $

Don't provide a declaration of gets and fgets
we're including stdio.h

--- lib/canna/lisp.c.orig	2004-04-26 22:49:21.000000000 +0000
+++ lib/canna/lisp.c
@@ -1355,8 +1355,6 @@ int c;
 static int
 tyi()
 {
-  char *gets(), *fgets();
-
   if (untyibuf) {
     int ret = untyibuf[--untyip];
     if (untyip == 0) {
