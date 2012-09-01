$NetBSD: patch-sope-core_NGStreams_NGLocalSocketAddress.m,v 1.1 2012/09/01 10:02:34 marino Exp $

--- sope-core/NGStreams/NGLocalSocketAddress.m.orig	2011-11-04 12:39:19.000000000 +0000
+++ sope-core/NGStreams/NGLocalSocketAddress.m
@@ -28,7 +28,7 @@
 
 #include "config.h"
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/types.h>
 #else
 #  include <sys/un.h>
