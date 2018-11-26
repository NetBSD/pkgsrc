$NetBSD: patch-src_actions.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/actions.c.orig	2003-03-14 01:06:36.000000000 +0000
+++ src/actions.c
@@ -32,7 +32,7 @@
 static char web_command[255] = "galeon -n *";
 static char mail_command[255] = "rxvt -rv +sb -e mutt *";
 
-static int cmd_system(int argc, char **argv, void *data){
+static uint64_t cmd_system(int argc, char **argv, void *data){
 	Node *pos=(Node *)data;
 	int ui_was_inited = ui_inited;
 	if (argc>1) {
@@ -42,7 +42,7 @@
 		if (ui_was_inited)
 			ui_init ();
 	}
-	return (int)pos;
+	return PTR_TO_UINT64(pos);
 }
 
 static int action_node (Node *node)
@@ -136,21 +136,21 @@
  * url/email address substring,.. and launches an app based on that?
  *
  */
-static int cmd_action (int argc, char **argv, void *data)
+static uint64_t cmd_action (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	Node *node = node_right (pos);
 
 	while (node) {
 		if (!action_node (node))
-			return (int) pos;
+			return PTR_TO_UINT64(pos);
 		node = node_down (node);
 	}
 	if (!action_node (pos)) {
-		return (int) pos;
+		return PTR_TO_UINT64(pos);
 	} else {
 		cli_outfunf ("nothing to do");
-		return (int) pos;
+		return PTR_TO_UINT64(pos);
 	}
 
 	/***
