$NetBSD: patch-include_r__local.h,v 1.1 2013/03/28 21:25:52 joerg Exp $

--- include/r_local.h.orig	2013-03-28 15:51:51.000000000 +0000
+++ include/r_local.h
@@ -255,7 +255,7 @@ qboolean R_AliasCheckBBox (void);
 
 void R_DrawParticles (void);
 void R_InitParticles (void);
-inline void R_ClearParticles (void);
+void R_ClearParticles (void);
 void R_ReadPointFile_f (void);
 void R_InitSprites (void);
 void R_SurfacePatch (void);
