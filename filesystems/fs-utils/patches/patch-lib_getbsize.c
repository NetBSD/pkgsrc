$NetBSD: patch-lib_getbsize.c,v 1.1 2013/06/26 21:24:23 joerg Exp $

--- lib/getbsize.c.orig	2013-06-26 20:19:49.000000000 +0000
+++ lib/getbsize.c
@@ -46,10 +46,6 @@ __RCSID("$NetBSD: getbsize.c,v 1.2 2009/
 
 #include "fsu_compat.h"
 
-#ifdef __weak_alias
-__weak_alias(getbsize,_getbsize)
-#endif
-
 char *
 getbsize(headerlenp, blocksizep)
 	int *headerlenp;
