$NetBSD: patch-deps_obs-scripting_obs-scripting-python.c,v 1.1 2025/08/20 06:15:38 wiz Exp $

Fix build with newer Python.

--- deps/obs-scripting/obs-scripting-python.c.orig	2025-08-20 06:13:55.296237069 +0000
+++ deps/obs-scripting/obs-scripting-python.c
@@ -1628,8 +1628,6 @@ bool obs_scripting_load_python(const cha
 #endif
 
 	PyEval_InitThreads();
-	if (!PyEval_ThreadsInitialized())
-		return false;
 
 	/* ---------------------------------------------- */
 	/* Must set arguments for guis to work            */
