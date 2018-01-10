$NetBSD: patch-src_layout__util.c,v 1.1 2018/01/10 09:38:32 wiz Exp $

1. For WEXITSTATUS().
2. Fix
layout_util.c: In function 'layout_menu_write_rotate':
layout_util.c:516:16: error: lvalue required as unary '&' operand

--- src/layout_util.c.orig	2017-12-31 12:31:21.000000000 +0000
+++ src/layout_util.c
@@ -58,6 +58,7 @@
 #include "metadata.h"
 #include "desktop_file.h"
 
+#include <sys/wait.h>
 #include <gdk/gdkkeysyms.h> /* for keyboard values */
 #include "keymap_template.c"
 
@@ -495,6 +496,7 @@ static void layout_menu_write_rotate(Gtk
 
 	while (work)
 		{
+		int ret;
 		if (lw->vf->type == FILEVIEW_ICON)
 			{
 			fd_n = work->data;
@@ -512,7 +514,8 @@ static void layout_menu_write_rotate(Gtk
 		command = g_strconcat(GQ_BIN_DIR, "/geeqie-rotate -r ", rotation,
 													keep_date ? " -t " : " ", fd_n->path, NULL);
 
-		run_result = WEXITSTATUS(runcmd(command));
+		ret = runcmd(command);
+		run_result = WEXITSTATUS(ret);
 		if (!run_result)
 			{
 			fd_n->user_orientation = 0;
