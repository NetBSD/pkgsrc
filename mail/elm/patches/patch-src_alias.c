$NetBSD: patch-src_alias.c,v 1.1 2013/02/26 11:08:17 joerg Exp $

--- src/alias.c.orig	2013-02-25 16:38:02.000000000 +0000
+++ src/alias.c
@@ -705,7 +705,7 @@ int num_to_delete;
 	return(0);
 }
 
-alias()
+void alias(void)
 {
 /*
  *	Work with alias commands...
