$NetBSD: patch-cfs.c,v 1.1 2012/10/26 20:24:19 joerg Exp $

--- cfs.c.orig	2012-10-26 13:19:27.000000000 +0000
+++ cfs.c
@@ -42,6 +42,7 @@
 #include "cfs.h"
 
 struct in_addr validhost;
+static void initstuff(void);
 
 #if defined(SOLARIS2X) || defined(__NetBSD__)
 void nfs_program_2();
@@ -227,7 +228,7 @@ main(argc,argv)
 	exit(1);
 }
 
-initstuff()
+static void initstuff(void)
 {
 	int i;
 	static instance ina,inb;
