$NetBSD: patch-sope-core_NGStreams_NGLocalSocketDomain.m,v 1.1 2019/09/11 11:32:26 tm Exp $

Add support for DragonFly.

--- sope-core/NGStreams/NGLocalSocketDomain.m.orig	2011-11-04 12:39:19.000000000 +0000
+++ sope-core/NGStreams/NGLocalSocketDomain.m
@@ -25,7 +25,7 @@
 #include "NGLocalSocketAddress.h"
 #include "NGSocket.h"

-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/types.h>
 #  include <sys/socket.h>
 #else
