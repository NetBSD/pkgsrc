$NetBSD: patch-lib_canna_lisp.c,v 1.2 2026/06/30 14:17:52 tsutsui Exp $

Don't provide a declaration of gets and fgets
we're including stdio.h

--- lib/canna/lisp.c.orig	2004-04-26 22:49:21.000000000 +0000
+++ lib/canna/lisp.c
@@ -1358,8 +1358,6 @@ int c;
 static int
 tyi()
 {
-  char *gets(), *fgets();
-
   if (untyibuf) {
     int ret = untyibuf[--untyip];
     if (untyip == 0) {
