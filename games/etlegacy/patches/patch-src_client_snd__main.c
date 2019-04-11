$NetBSD: patch-src_client_snd__main.c,v 1.1 2019/04/11 20:56:34 nia Exp $

Default to OpenAL over SDL2 - eliminates stuttering on NetBSD.

--- src/client/snd_main.c.orig	2019-01-05 19:54:35.000000000 +0000
+++ src/client/snd_main.c
@@ -809,7 +809,7 @@ void S_StopMusic_f(void)
  */
 void S_Init(void)
 {
-	cvar_t *cv = Cvar_Get("s_initsound", "1", CVAR_ARCHIVE | CVAR_LATCH | CVAR_UNSAFE);  // 0 = disabled, 1 = SDL2, 2 = OpenAL
+	cvar_t *cv = Cvar_Get("s_initsound", "2", CVAR_ARCHIVE | CVAR_LATCH | CVAR_UNSAFE);  // 0 = disabled, 1 = SDL2, 2 = OpenAL
 
 	Com_Printf("------ Initializing Sound (%i)------\n", cv->integer);
 
