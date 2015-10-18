$NetBSD: patch-lib_RK_ncache.c,v 1.1 2015/10/18 03:58:31 tsutsui Exp $

Fix crash problem of cannaserver.

--- lib/RK/ncache.c.orig	2003-09-17 08:50:52.000000000 +0000
+++ lib/RK/ncache.c
@@ -27,7 +27,7 @@ static char rcsid[]="$Id: ncache.c,v 1.2
 #include	"RKintern.h"
 
 #define	NCHASH		101
-#define	hash(x)		((int)((x)%NCHASH))
+#define	hash(x)		((int)(((unsigned long)(x))%NCHASH))
 
 static struct ncache	Nchash[NCHASH];
 static struct ncache	Ncfree;
