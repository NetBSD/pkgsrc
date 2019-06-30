$NetBSD: patch-src_noise.h,v 1.1 2019/06/30 22:27:22 nia Exp $

Avoid colliding with NetBSD libc.

--- src/noise.h.orig	2019-03-31 20:57:45.000000000 +0000
+++ src/noise.h
@@ -29,6 +29,8 @@
 #include "exceptions.h"
 #include "util/string.h"
 
+#undef RANDOM_MAX
+
 extern FlagDesc flagdesc_noiseparams[];
 
 // Note: this class is not polymorphic so that its high level of
