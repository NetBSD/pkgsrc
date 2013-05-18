$NetBSD: patch-src_module.cc,v 1.1 2013/05/18 20:23:03 adam Exp $

Darwin actually expects .so extension.

--- src/module.cc.orig	2013-05-18 18:29:32.000000000 +0000
+++ src/module.cc
@@ -117,11 +117,7 @@ static ResDecl res_mod_path("module:path
 /* dlopen can take a file without extension and automatically do the
  * right thing, however that doesn't fit with this code that tries to
  * stat before the dlopen call, hence need some help here */
-#if defined(__MACH__) && defined(__APPLE__)
-static const char ext[] = ".bundle";
-#else
 static const char ext[] = ".so";
-#endif
 
 static int access_so(xstring &fullpath)
 {
