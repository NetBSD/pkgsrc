$NetBSD: patch-src_suggestions.c,v 1.1 2018/11/27 14:29:27 bsiegert Exp $

Use new soname for enchant2.

--- src/suggestions.c.orig	2012-10-06 18:25:42.000000000 +0000
+++ src/suggestions.c
@@ -32,7 +32,7 @@
 #ifdef _WIN32
 #	define ENCHANT_FILE		"libenchant.dll"
 #else
-#	define ENCHANT_FILE		"libenchant.so.1"
+#	define ENCHANT_FILE		"libenchant-2.so.2"
 #endif
 #define	DICT_TAG_MAX_LENGTH	7
 
