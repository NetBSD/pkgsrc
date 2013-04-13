$NetBSD: patch-libsrc_plugin_dlf.h,v 1.1 2013/04/13 13:16:02 jaapb Exp $

NetBSD has libdl as well
--- libsrc/plugin/dlf.h.orig	2012-03-23 12:28:31.000000000 +0000
+++ libsrc/plugin/dlf.h
@@ -44,7 +44,7 @@
 #endif /* defined (__APPLE_) */
 
 /* dlopen stuff */
-#if defined(HAVE_LIBDL) || defined(__FreeBSD__)
+#if defined(HAVE_LIBDL) || defined(__FreeBSD__) || defined(__NetBSD__)
 #define DLDAPI_SVR4_DLFCN
 #elif defined(HAVE_SHL_LOAD)
 #define DLDAPI_HP_SHL
