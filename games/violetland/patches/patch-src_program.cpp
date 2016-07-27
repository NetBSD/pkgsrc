$NetBSD: patch-src_program.cpp,v 1.1 2016/07/27 21:14:36 kamil Exp $

Add NetBSD support.

--- src/program.cpp.orig	2016-07-27 09:04:07.000000000 +0000
+++ src/program.cpp
@@ -244,8 +244,11 @@ void printVersion() {
 	env = "GNU/LINUX";
 #endif //linux
 #ifdef __FreeBSD__
-	env = "BSD";
+	env = "FREEBSD";
 #endif //__FreeBSD__
+#ifdef __NetBSD__
+	env = "NETBSD";
+#endif //__NetBSD__
 #ifdef __APPLE__
 	env = "MAC";
 #endif //__APPLE__
