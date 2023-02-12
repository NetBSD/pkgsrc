$NetBSD: patch-src_OSD_OSD__Path.cxx,v 1.1 2023/02/12 14:42:25 tnn Exp $

NetBSD support

--- src/OSD/OSD_Path.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/OSD/OSD_Path.cxx
@@ -19,7 +19,7 @@
 
 static OSD_SysType whereAmI()
 {
-#if defined(__digital__) || defined(__FreeBSD__) || defined(SUNOS) || defined(__APPLE__) || defined(__QNX__) || defined(__FreeBSD_kernel__)
+#if defined(__digital__) || defined(__FreeBSD__) || defined(SUNOS) || defined(__APPLE__) || defined(__QNX__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
   return OSD_UnixBSD;
 #elif defined(sgi)  || defined(IRIX) || defined(__sun)  || defined(SOLARIS) ||  defined(__sco__) || defined(__hpux) || defined(HPUX)
   return OSD_UnixSystemV;
