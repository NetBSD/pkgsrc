$NetBSD: patch-src_mulMats.c,v 1.1 2012/10/20 22:03:46 joerg Exp $

--- src/mulMats.c.orig	2012-10-20 10:19:34.000000000 +0000
+++ src/mulMats.c
@@ -706,8 +706,7 @@ children's multipoles or charges. Note t
 multipole to multipole matrices is computed per level by exploiting the
 uniform break-up of three-space (ie many shifts have similar geometries).  
 */
-mulMatUp(sys) 
-ssystem *sys; 
+void mulMatUp(ssystem *sys)
 {
 cube *nextc, *kid;
 int i, j, numterms, depth, order = sys->order;
