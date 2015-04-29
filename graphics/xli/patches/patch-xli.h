$NetBSD: patch-xli.h,v 1.1 2015/04/29 15:52:53 gson Exp $

Rename zopen to avoid conflict with a function by the same
name defined in stdio.h on Mac OS X.

--- xli.h.orig	1999-10-25 02:15:07.000000000 +0000
+++ xli.h
@@ -338,6 +338,9 @@ void flipBits(byte *p, unsigned int len)
 int xpmoption(char *s);
 
 /* zio.c */
+#ifdef __APPLE__
+#define zopen zzopen
+#endif
 ZFILE *zopen(char *name);
 int zread(ZFILE *zf, byte *buf, int len);
 int zeof(ZFILE *zf);
