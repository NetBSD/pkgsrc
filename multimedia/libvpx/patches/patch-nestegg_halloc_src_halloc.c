$NetBSD: patch-nestegg_halloc_src_halloc.c,v 1.1 2015/06/29 21:09:11 markd Exp $

rename to avoid conflict with gcc5.x stddef.h

--- nestegg/halloc/src/halloc.c.orig	2013-11-18 22:18:52.000000000 +0000
+++ nestegg/halloc/src/halloc.c
@@ -30,7 +30,7 @@ typedef struct hblock
 #endif
 	hlist_item_t  siblings; /* 2 pointers */
 	hlist_head_t  children; /* 1 pointer  */
-	max_align_t   data[1];  /* not allocated, see below */
+	h_max_align_t   data[1];  /* not allocated, see below */
 	
 } hblock_t;
 
