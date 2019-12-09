$NetBSD: patch-src_cares__wrap.cc,v 1.1 2019/12/09 20:05:40 adam Exp $

NetBSD has no AI_V4MAPPED.

--- src/cares_wrap.cc.orig	2017-05-30 17:32:13.000000000 +0000
+++ src/cares_wrap.cc
@@ -47,7 +47,7 @@
 # include <arpa/nameser.h>
 #endif
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 # define AI_V4MAPPED 0
 #endif
 
