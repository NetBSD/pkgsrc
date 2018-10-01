$NetBSD: patch-libelftc___libelftc.h,v 1.2 2018/10/01 12:36:35 ryoon Exp $

avoid error - cast float value to size_t before using it

--- libelftc/_libelftc.h.orig	2015-03-27 17:13:41.000000000 +0000
+++ libelftc/_libelftc.h
@@ -55,7 +55,7 @@ struct vector_str {
 	char		**container;
 };
 
-#define BUFFER_GROWFACTOR	1.618
+#define BUFFER_GROWFACTOR	((size_t)1.618)
 
 #define	ELFTC_FAILURE		0
 #define	ELFTC_ISDIGIT(C) 	(isdigit((C) & 0xFF))
