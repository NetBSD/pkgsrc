$NetBSD: patch-src_version.h,v 1.1 2022/11/27 13:14:01 triaxx Exp $

Fix version increment which has been forgotten at releasing date.

--- src/version.h.orig	2021-07-01 16:59:57.000000000 +0000
+++ src/version.h
@@ -1,12 +1,12 @@
 #ifndef VERSION
-#define VERSION "3proxy-0.9.3"
+#define VERSION "3proxy-0.9.4"
 #endif
 #ifndef BUILDDATE
 #define BUILDDATE ""
 #endif
 #define MAJOR3PROXY 0
 #define SUBMAJOR3PROXY 9
-#define MINOR3PROXY 3
+#define MINOR3PROXY 4
 #define SUBMINOR3PROXY 0
-#define RELEASE3PROXY "3proxy-0.9.3(" BUILDDATE ")\0"
+#define RELEASE3PROXY "3proxy-0.9.4(" BUILDDATE ")\0"
 #define YEAR3PROXY "2021"
