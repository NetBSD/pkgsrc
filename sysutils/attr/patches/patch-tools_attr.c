$NetBSD: patch-tools_attr.c,v 1.3 2025/10/07 05:29:46 wiz Exp $

Add missing header for basename().

--- tools/attr.c.orig	2025-10-07 05:28:37.594126215 +0000
+++ tools/attr.c
@@ -28,6 +28,7 @@
 #include <errno.h>
 #include <string.h>
 #include <locale.h>
+#include <libgen.h>
 
 #include <attr/attributes.h>
 
