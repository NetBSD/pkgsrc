$NetBSD: patch-common-src_genversion.c,v 1.1 2018/11/23 22:33:13 spz Exp $

pkgsrcification

--- common-src/genversion.c.orig	2016-02-09 22:52:51.000000000 +0000
+++ common-src/genversion.c
@@ -445,9 +445,11 @@ main(
     prvar("UNCOMPRESS_OPT", UNCOMPRESS_OPT);
 #endif
 
+/* makes the workdir references check complain and isn't that useful
 #ifdef CONFIGURE_ARGS
     prvar("CONFIGURE_ARGS", CONFIGURE_ARGS);
 #endif
+*/
 
     endline();
 
