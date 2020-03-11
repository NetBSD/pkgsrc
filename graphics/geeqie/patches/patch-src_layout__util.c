$NetBSD: patch-src_layout__util.c,v 1.3 2020/03/11 11:05:53 wiz Exp $

For WEXITSTATUS().
https://github.com/BestImageViewer/geeqie/pull/759

--- src/layout_util.c.orig	2017-12-31 12:31:21.000000000 +0000
+++ src/layout_util.c
@@ -58,6 +58,7 @@
 #include "metadata.h"
 #include "desktop_file.h"
 
+#include <sys/wait.h>
 #include <gdk/gdkkeysyms.h> /* for keyboard values */
 #include "keymap_template.c"
 
