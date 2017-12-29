$NetBSD: patch-tools.h,v 1.1 2017/12/29 17:55:13 maya Exp $

malloc+memset to calloc

--- tools.h.orig	2009-03-08 14:25:53.000000000 +0000
+++ tools.h
@@ -74,10 +74,9 @@
 
 #define XMALLOC(elm, size)						\
 	do {								\
-		elm = malloc(size);					\
+		elm = calloc(1, size);					\
 		if (elm == NULL)					\
 			err(1, "can't allocate memory\n");		\
-		memset(elm, 0, size);					\
 	} while (/* CONSTCOND */ 0)
 
 #define XSTRDUP(dest, src)						\
