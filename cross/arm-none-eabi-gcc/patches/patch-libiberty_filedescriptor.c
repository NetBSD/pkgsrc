$NetBSD: patch-libiberty_filedescriptor.c,v 1.1 2026/04/20 03:49:24 js Exp $

--- libiberty/filedescriptor.c.orig	2025-06-15 13:08:22.076607890 +0000
+++ libiberty/filedescriptor.c
@@ -23,6 +23,8 @@
 #include "ansidecl.h"
 #include "libiberty.h"
 
+#include <unistd.h>
+
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #endif
