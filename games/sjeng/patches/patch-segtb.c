$NetBSD: patch-segtb.c,v 1.1 2013/01/11 23:26:36 joerg Exp $

--- segtb.c.orig	2013-01-11 14:40:04.000000000 +0000
+++ segtb.c
@@ -703,7 +703,7 @@ void free_egtb()
 }
 
 
-int init_segtb()
+void init_segtb(void)
 {
   int i;
   
@@ -733,8 +733,6 @@ int init_segtb()
 	 (21 * TWO_PIECE_SIZE) / 1024);
   printf("Three-piece suicide endgame table cache %d kB\n", 
 	 (CACHE_SIZE * THREE_PIECE_SIZE) / 1024);
-  
-  return 1;
 }
 
 
