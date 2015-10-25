$NetBSD: patch-lib_RK_ncache.c,v 1.2 2015/10/25 12:17:36 tsutsui Exp $

Pull upstream fix to avoid crash problem of cannaserver.
 https://osdn.jp/cvs/view/canna/canna/lib/RK/ncache.c?view=log#rev1.3

--- lib/RK/ncache.c.orig	2003-09-17 08:50:52.000000000 +0000
+++ lib/RK/ncache.c
@@ -27,7 +27,7 @@ static char rcsid[]="$Id: ncache.c,v 1.2
 #include	"RKintern.h"
 
 #define	NCHASH		101
-#define	hash(x)		((int)((x)%NCHASH))
+#define	hash(x)		((int)(((unsigned long)(x))%NCHASH))
 
 static struct ncache	Nchash[NCHASH];
 static struct ncache	Ncfree;
