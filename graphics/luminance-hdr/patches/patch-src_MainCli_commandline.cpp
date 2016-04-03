$NetBSD: patch-src_MainCli_commandline.cpp,v 1.1 2016/04/03 12:47:45 joerg Exp $

--- src/MainCli/commandline.cpp.orig	2016-04-02 18:17:21.047535103 +0000
+++ src/MainCli/commandline.cpp
@@ -47,6 +47,10 @@
 #include <io.h>
 #endif
 
+#ifdef __NetBSD__
+#define getopt_long_only getopt_long
+#endif
+
 namespace
 {
 void printErrorAndExit(const QString& error_str)
