$NetBSD: patch-src_support_filetools.cpp,v 1.1 2026/06/13 09:51:21 markd Exp $

define WEXITSTATUS()

--- src/support/filetools.cpp.orig	2026-04-12 18:55:40.000000000 +0000
+++ src/support/filetools.cpp
@@ -49,6 +49,7 @@
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#include <sys/wait.h>
 
 #include <cerrno>
 #include <climits>
