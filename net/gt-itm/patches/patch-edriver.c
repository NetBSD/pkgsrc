$NetBSD: patch-edriver.c,v 1.1 2012/12/25 21:05:20 joerg Exp $

--- edriver.c.orig	2012-12-25 18:51:09.000000000 +0000
+++ edriver.c
@@ -68,7 +68,7 @@ main(argc,argv)
 
     if (argc == 1) {
 	printf("Usage: edriver <filestem> [-nd] [-<f0><f1>]*\n\n");
-	return;
+	return 1;
     }
     /* determine whether to print distributions */
     /* determine where in argv the field pairs begin */
