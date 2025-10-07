$NetBSD: patch-tools_attr.c,v 1.4 2025/10/07 11:54:05 wiz Exp $

Add missing header for basename().
https://cgit.git.savannah.gnu.org/cgit/attr.git/commit/?id=8a80d895dfd779373363c3a4b62ecce5a549efb2

--- tools/attr.c.orig	2025-10-07 05:28:37.594126215 +0000
+++ tools/attr.c
@@ -28,6 +28,7 @@
 #include <errno.h>
 #include <string.h>
 #include <locale.h>
+#include <libgen.h>
 
 #include <attr/attributes.h>
 
