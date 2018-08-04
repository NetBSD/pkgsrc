$NetBSD: patch-src_osg_GLExtensions.cpp,v 1.1 2018/08/04 01:05:10 nia Exp $

Support NetBSD.

--- src/osg/GLExtensions.cpp.orig	2017-04-03 10:44:31.000000000 +0000
+++ src/osg/GLExtensions.cpp
@@ -378,7 +378,7 @@ OSG_INIT_SINGLETON_PROXY(GLExtensionDisa
         static void *handle = dlopen((const char *)0L, RTLD_LAZY);
         return dlsym(handle, funcName);
 
-    #elif defined (__FreeBSD__)
+    #elif defined (__FreeBSD__) || defined (__NetBSD__)
 
         return dlsym( RTLD_DEFAULT, funcName );
 
