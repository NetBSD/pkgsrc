$NetBSD: patch-cmd_catdic_rutil.c,v 1.1 2018/03/23 04:43:36 rin Exp $

Fix buffer over run in mkdic, found by stack protector.

--- cmd/catdic/rutil.c.orig	2018-03-23 13:28:58.453648806 +0900
+++ cmd/catdic/rutil.c	2018-03-23 13:29:11.364912041 +0900
@@ -308,7 +308,7 @@ int cn;
 unsigned char *dicname;
 int mode ;
 {
-  char ans[79];
+  char ans[80];
   int ret = 0;
 
   static int  majv , minv , bak ;
