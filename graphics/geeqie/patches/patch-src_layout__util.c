$NetBSD: patch-src_layout__util.c,v 1.2 2019/07/30 13:03:18 ryoon Exp $

For WEXITSTATUS().

--- src/layout_util.c.orig	2017-12-31 12:31:21.000000000 +0000
+++ src/layout_util.c
@@ -58,6 +58,7 @@
 #include "metadata.h"
 #include "desktop_file.h"
 
+#include <sys/wait.h>
 #include <gdk/gdkkeysyms.h> /* for keyboard values */
 #include "keymap_template.c"
 
