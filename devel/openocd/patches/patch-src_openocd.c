$NetBSD: patch-src_openocd.c,v 1.1 2025/04/06 10:07:06 adam Exp $

Fix build with jimtcl 0.83.

--- src/openocd.c.orig	2025-04-06 05:49:36.109698542 +0000
+++ src/openocd.c
@@ -255,9 +255,9 @@ static int jim_expr_command(Jim_Interp *
 		Jim_Obj *obj = Jim_ConcatObj(interp, argc - 1, argv + 1);
 		Jim_IncrRefCount(obj);
 		const char *s = Jim_String(obj);
-		struct jim_scriptobj *script = Jim_GetIntRepPtr(interp->currentScriptObj);
-		if (interp->currentScriptObj == interp->emptyObj ||
-				strcmp(interp->currentScriptObj->typePtr->name, "script") ||
+		struct jim_scriptobj *script = Jim_GetIntRepPtr(interp->unused_currentScriptObj);
+		if (interp->unused_currentScriptObj == interp->emptyObj ||
+				strcmp(interp->unused_currentScriptObj->typePtr->name, "script") ||
 				script->subst_flags ||
 				script->filename_obj == interp->emptyObj)
 			LOG_WARNING("DEPRECATED! use 'expr { %s }' not 'expr %s'", s, s);
