$NetBSD: patch-utils_process_systembuf_test.cpp,v 1.1 2012/05/24 16:47:11 marino Exp $

--- utils/process/systembuf_test.cpp.orig	2012-01-16 17:31:50.000000000 +0000
+++ utils/process/systembuf_test.cpp
@@ -29,6 +29,9 @@
 #include "utils/process/systembuf.hpp"
 
 extern "C" {
+#ifdef __DragonFly__
+#include <sys/stat.h>
+#endif
 #include <fcntl.h>
 #include <unistd.h>
 }
