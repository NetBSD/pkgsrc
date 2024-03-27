$NetBSD: patch-libiberty_filedescriptor.c,v 1.1 2024/03/27 14:38:33 js Exp $

--- libiberty/filedescriptor.c.orig	2024-03-27 12:10:46.525851695 +0000
+++ libiberty/filedescriptor.c
@@ -26,6 +26,9 @@
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #endif
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 
 #if defined (_WIN32)
 #define WIN32_LEAN_AND_MEAN
