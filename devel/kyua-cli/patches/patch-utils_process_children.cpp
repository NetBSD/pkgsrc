$NetBSD: patch-utils_process_children.cpp,v 1.1 2012/05/24 16:47:11 marino Exp $

--- utils/process/children.cpp.orig	2012-02-24 15:48:46.000000000 +0000
+++ utils/process/children.cpp
@@ -29,6 +29,9 @@
 extern "C" {
 #include <sys/wait.h>
 
+#ifdef __DragonFly__
+#include <sys/stat.h>
+#endif
 #include <fcntl.h>
 #include <signal.h>
 #include <unistd.h>
