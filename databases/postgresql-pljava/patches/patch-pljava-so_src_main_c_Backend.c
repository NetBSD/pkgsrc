$NetBSD: patch-pljava-so_src_main_c_Backend.c,v 1.1 2017/10/27 09:51:03 fhajny Exp $

Set a default libjvm path, because we can and it saves user an awkward step.

--- pljava-so/src/main/c/Backend.c.orig	2016-03-29 16:52:02.000000000 +0000
+++ pljava-so/src/main/c/Backend.c
@@ -1291,7 +1291,7 @@ static void registerGUCOptions(void)
 		NULL, /* extended description */
 		&libjvmlocation,
 		#if PG_VERSION_NUM >= 80400
-			"libjvm",
+			"@LIBJVM@",
 		#endif
 		PGC_SUSET,
 		#if PG_VERSION_NUM >= 80400
