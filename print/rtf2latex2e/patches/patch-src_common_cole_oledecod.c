$NetBSD: patch-src_common_cole_oledecod.c,v 1.1 2014/04/17 21:34:16 asau Exp $

--- src/common/cole/oledecod.c.orig	2001-05-18 19:00:46.000000000 +0000
+++ src/common/cole/oledecod.c
@@ -44,7 +44,6 @@
 #if __GNUC__
 	#if __APPLE__
 	#else
-	#include <malloc.h>
 	#endif
 	#include <sys/types.h>
 #endif	
