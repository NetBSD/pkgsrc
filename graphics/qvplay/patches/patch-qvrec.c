$NetBSD: patch-qvrec.c,v 1.1 2012/11/01 19:50:59 joerg Exp $

--- qvrec.c.orig	2012-10-30 22:18:26.000000000 +0000
+++ qvrec.c
@@ -617,12 +617,12 @@ main(argc, argv)
 		if(QVremain(1) < 0){
 			fprintf(stderr, "picture full.\n");
 			errflg ++;
-			return;
+			return 1;
 		}
 		if(QVremain(0) < 0){
 			fprintf(stderr, "picture full.\n");
 			errflg ++;
-			return;
+			return 1;
 		}
 	} else {
 		if(all_pic_num >= MAX_PICTURE_NUM_QV10) {
@@ -659,12 +659,12 @@ main(argc, argv)
 		if(QVremain(1) < 0){
 			fprintf(stderr, "picture full.\n");
 			errflg ++;
-			return;
+			return 1;
 		}
 		if(QVremain(0) < 0){
 			fprintf(stderr, "picture full.\n");
 			errflg ++;
-			return;
+			return 1;
 		}
 	  } else {
 		  if(all_pic_num >= MAX_PICTURE_NUM_QV10) {
