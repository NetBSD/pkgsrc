$NetBSD: patch-desmume_src_wifi.cpp,v 1.1 2019/05/12 09:49:39 nia Exp $

https://github.com/libretro/desmume/issues/58

--- desmume/src/wifi.cpp.orig	2019-04-26 20:09:47.000000000 +0000
+++ desmume/src/wifi.cpp
@@ -59,7 +59,7 @@
 
 // Some platforms need HAVE_REMOTE to work with libpcap, but
 // Apple platforms are not among them.
-#ifndef __APPLE__
+#if !defined( __APPLE__) && !defined(__LIBRETRO__)
 	#define HAVE_REMOTE
 #endif
 
