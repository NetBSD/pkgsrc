$NetBSD: patch-src_ui_input.c,v 1.1 2025/12/29 03:10:14 ktnb Exp $

Need wchar.h for wcwidth.

--- src/ui/input.c.orig	2025-12-18 09:54:42.000000000 +0000
+++ src/ui/input.c
@@ -41,6 +41,7 @@
 #include <ctype.h>
 #include <gio/gio.h>
 #include <glib.h>
+#include <wchar.h>
 
 #define MAX_TMP_SEQ_LEN 256
 #define NUM_KEY_MAPPINGS 64
