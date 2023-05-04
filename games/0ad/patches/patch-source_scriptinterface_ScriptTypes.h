$NetBSD: patch-source_scriptinterface_ScriptTypes.h,v 1.1 2023/05/04 15:20:52 nikita Exp $

--- source/scriptinterface/ScriptTypes.h.orig	2021-07-27 21:56:58.000000000 +0000
+++ source/scriptinterface/ScriptTypes.h
@@ -81,6 +81,7 @@ system-installed version. Make sure you 
 include paths.
 #endif
 
+#if 0
 #if MOZJS_MINOR_VERSION != 6
 #error Your compiler is trying to use an untested minor version of the \
 SpiderMonkey library. If you are a package maintainer, please make sure \
@@ -93,6 +94,7 @@ version. Another way for testing is runn
 final hash (check trac.wildfiregames.com/wiki/Debugging#Replaymode). \
 For more information check this link: trac.wildfiregames.com/wiki/Debugging#Outofsync
 #endif
+#endif
 
 class ScriptInterface;
 
