$NetBSD: patch-src_modules_openfx_factory.c,v 1.1 2026/09/06 09:56:09 markd Exp $

Add NetBSD

--- src/modules/openfx/factory.c.orig	2026-06-25 00:09:29.000000000 +0000
+++ src/modules/openfx/factory.c
@@ -25,7 +25,7 @@ extern OfxHost MltOfxHost;
 mlt_properties mltofx_context;
 mlt_properties mltofx_dl;
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 #define OFX_DIRLIST_SEP_CHARS ":;"
 #define OFX_DIRSEP "/"
@@ -36,12 +36,16 @@ static const char *getArchStr()
     if (sizeof(void *) == 4) {
 #if defined(__linux__)
         return "Linux-x86";
+#elif defined(__NetBSD__)
+        return "NetBSD-x86";
 #else
         return "FreeBSD-x86";
 #endif
     } else {
 #if defined(__linux__)
         return "Linux-x86-64";
+#elif defined(__NetBSD__)
+        return "NetBSD-x86-64";
 #else
         return "FreeBSD-x86-64";
 #endif
@@ -312,7 +316,7 @@ MLT_REPOSITORY
     int dli = 0;
 
     // Scan standard platform default paths per the OpenFX specification
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
     scan_ofx_dir(repository, "/usr/OFX/Plugins", &dli, 0);
     scan_ofx_dir(repository, "/usr/local/OFX/Plugins", &dli, 0);
 #elif defined(__APPLE__)
