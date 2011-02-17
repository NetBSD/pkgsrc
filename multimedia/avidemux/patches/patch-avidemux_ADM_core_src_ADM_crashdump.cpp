$NetBSD: patch-avidemux_ADM_core_src_ADM_crashdump.cpp,v 1.1 2011/02/17 09:20:17 markd Exp $

--- avidemux/ADM_core/src/ADM_crashdump.cpp.orig	2009-09-25 07:16:58.000000000 +0000
+++ avidemux/ADM_core/src/ADM_crashdump.cpp
@@ -47,7 +47,7 @@ void ADM_setCrashHook(ADM_saveFunction *
 extern char *ADM_getBaseDir(void);
 extern void A_parseECMAScript(const char *name);
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__) || defined(__DragonFly__)
 void installSigHandler() {}
 
 void ADM_backTrack(const char *info,int lineno,const char *file)
