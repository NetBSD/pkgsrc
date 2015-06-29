$NetBSD: patch-nestegg_halloc_src_align.h,v 1.1 2015/06/29 21:09:11 markd Exp $

rename to avoid conflict with gcc5.x stddef.h

--- nestegg/halloc/src/align.h.orig	2013-11-18 22:18:52.000000000 +0000
+++ nestegg/halloc/src/align.h
@@ -30,7 +30,7 @@ union max_align
 	void (*q)(void);
 };
 
-typedef union max_align max_align_t;
+typedef union max_align h_max_align_t;
 
 #endif
 
