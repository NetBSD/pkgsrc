$NetBSD: patch-src_fasthenry_mulMats.c,v 1.1 2012/12/25 21:14:17 joerg Exp $

--- src/fasthenry/mulMats.c.orig	2012-12-25 16:36:50.000000000 +0000
+++ src/fasthenry/mulMats.c
@@ -718,8 +718,7 @@ children's multipoles or charges. Note t
 multipole to multipole matrices is computed per level by exploiting the
 uniform break-up of three-space (ie many shifts have similar geometries).  
 */
-mulMatUp(sys) 
-ssystem *sys; 
+void mulMatUp(ssystem *sys)
 {
 cube *nextc, *kid;
 int i, j, numterms, depth, order = sys->order;
