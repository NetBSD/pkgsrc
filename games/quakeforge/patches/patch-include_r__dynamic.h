$NetBSD: patch-include_r__dynamic.h,v 1.1 2013/03/28 21:25:52 joerg Exp $

--- include/r_dynamic.h.orig	2013-03-28 15:51:46.000000000 +0000
+++ include/r_dynamic.h
@@ -79,7 +79,7 @@ void R_Particles_Init_Cvars (void);
 void R_InitBubble (void);
 
 void R_InitParticles (void);
-inline void R_ClearParticles (void);
+void R_ClearParticles (void);
 void R_DrawParticles (void);
 struct cvar_s;
 void R_MaxParticlesCheck (struct cvar_s *r_particles,
