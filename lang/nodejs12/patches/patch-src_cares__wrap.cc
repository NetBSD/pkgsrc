$NetBSD: patch-src_cares__wrap.cc,v 1.3 2020/05/30 20:45:12 joerg Exp $

NetBSD has neither AI_V4MAPPED nor AI_ALL.

--- src/cares_wrap.cc.orig	2020-05-26 11:53:34.000000000 +0000
+++ src/cares_wrap.cc
@@ -49,8 +49,9 @@
 # include <arpa/nameser.h>
 #endif
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 # define AI_V4MAPPED 0
+# define AI_ALL 0
 #endif
 
 namespace node {
