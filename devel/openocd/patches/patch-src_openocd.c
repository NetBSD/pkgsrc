$NetBSD: patch-src_openocd.c,v 1.2 2026/09/21 11:37:52 bouyer Exp $

Fix build with jimtcl 0.84.

--- src/openocd.c.orig	2022-09-18 15:46:16.000000000 +0200
+++ src/openocd.c	2026-09-20 23:39:56.430639363 +0200
@@ -255,15 +255,8 @@
 		Jim_Obj *obj = Jim_ConcatObj(interp, argc - 1, argv + 1);
 		Jim_IncrRefCount(obj);
 		const char *s = Jim_String(obj);
-		struct jim_scriptobj *script = Jim_GetIntRepPtr(interp->currentScriptObj);
-		if (interp->currentScriptObj == interp->emptyObj ||
-				strcmp(interp->currentScriptObj->typePtr->name, "script") ||
-				script->subst_flags ||
-				script->filename_obj == interp->emptyObj)
-			LOG_WARNING("DEPRECATED! use 'expr { %s }' not 'expr %s'", s, s);
-		else
-			LOG_WARNING("DEPRECATED! (%s:%d) use 'expr { %s }' not 'expr %s'",
-						Jim_String(script->filename_obj), script->linenr, s, s);
+		LOG_WARNING("DEPRECATED! use 'expr { %s }' not 'expr %s'", s, s);
+
 		int retcode = Jim_EvalExpression(interp, obj);
 		Jim_DecrRefCount(interp, obj);
 		return retcode;
