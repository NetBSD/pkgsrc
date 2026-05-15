$NetBSD: patch-lib_local__filesys.cpp,v 1.1 2026/05/15 07:31:37 wiz Exp $

Add header for PATH_MAX.
https://trac.filezilla-project.org/ticket/13397

--- lib/local_filesys.cpp.orig	2026-05-15 07:27:25.341002261 +0000
+++ lib/local_filesys.cpp
@@ -16,6 +16,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <utime.h>
+#include <limits.h>
 #endif
 
 namespace fz {
