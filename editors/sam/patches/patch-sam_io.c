$NetBSD: patch-sam_io.c,v 1.1 2017/09/21 14:37:40 bsiegert Exp $

--- sam/io.c.orig	2017-09-21 13:54:43.000000000 +0000
+++ sam/io.c
@@ -2,7 +2,9 @@
 #include "sam.h"
 
 #define	NSYSFILE	3
+#ifndef NOFILE
 #define	NOFILE		128
+#endif
 
 void
 checkqid(File *f)
