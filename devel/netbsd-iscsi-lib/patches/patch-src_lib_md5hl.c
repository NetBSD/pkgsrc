$NetBSD: patch-src_lib_md5hl.c,v 1.1.2.2 2015/10/24 19:25:36 bsiegert Exp $

--- src/lib/md5hl.c.orig	2015-09-12 20:57:55.447892750 +0000
+++ src/lib/md5hl.c
@@ -48,8 +48,8 @@
 #include <unistd.h>
 #endif
 
-#define	CONCAT(x,y)	__CONCAT(x,y)
-#define	MDNAME(x)	CONCAT(MDALGORITHM,x)
+#define	CONCAT(x,y)	x ## y
+#define	MDNAME(x)	CONCAT(iSCSI_MD5,x)
 
 char *
 MDNAME(End)(MDNAME(_CTX) *ctx, char *buf)
