$NetBSD: patch-src_clexheaders.h,v 1.1 2012/02/17 13:23:28 obache Exp $

* Need to treat *BSD same as FreeBSD.

--- src/clexheaders.h.orig	2009-01-11 19:44:35.000000000 +0000
+++ src/clexheaders.h
@@ -1,4 +1,4 @@
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 # define _XOPEN_SOURCE 600
 #endif
 
