$NetBSD: patch-src_tree__misc.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/tree_misc.c.orig	2003-03-14 00:31:02.000000000 +0000
+++ src/tree_misc.c
@@ -27,12 +27,12 @@
 #include "ui_cli.h"
 #include "evilloop.h"
 
-static int cmd_movenode (int argc, char **argv, void *data)
+static uint64_t  cmd_movenode (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	if(argc<2){
 		cli_outfunf("usage: %s <left|right|up|down>",argv[0]);
-		return (int)pos;
+		return PTR_TO_UINT64(pos);
 	}
 	if (!strcmp (argv[1], "left")) {
 		if (node_left (pos)) {
@@ -64,7 +64,7 @@ static int cmd_movenode (int argc, char 
 			node_swap (pos, node_down (pos));
 		}
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
@@ -75,12 +75,12 @@
 	cli_add_command ("movenode", cmd_movenode, "<up|left|right|down>");
 }
 
-static int cmd_go(int argc, char **argv, void *data){
+static uint64_t cmd_go(int argc, char **argv, void *data){
 	Node *pos=(Node *)data;
 	
 	if(argc!=2){
 		cli_outfunf("usage: %s <up|down|left|right|recurse|backrecurse|root|top|bottom>");
-		return (int)pos;
+		return PTR_TO_UINT64(pos);
 	}
 	
 	if(!strcmp(argv[1],"up")){
@@ -110,7 +110,7 @@
 	}
 
 	
-	return (int)pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
@@ -126,7 +126,7 @@ void init_go ()
 #include "ctype.h"
 #include "ui_binding.h"
 
-static int cmd_outdent (int argc, char **argv, void *data)
+static uint64_t cmd_outdent (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -135,7 +135,7 @@
 			inputbuf[strlen (inputbuf) + 1] = 0;
 			inputbuf[strlen (inputbuf)] = lastbinding->key;
 		}		
-		return (int)pos;
+		return PTR_TO_UINT64(pos);
 	}
 
 	if (node_left (pos)) {
@@ -166,12 +166,12 @@ static int cmd_outdent (int argc, char *
 			target_node->right = NULL;
 		}
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*	FIXME: no real need for a temporary node */
 
-static int cmd_indent (int argc, char **argv, void *data)
+static uint64_t cmd_indent (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -180,7 +180,7 @@
 			inputbuf[strlen (inputbuf) + 1] = 0;
 			inputbuf[strlen (inputbuf)] = lastbinding->key;
 		}		
-		return (int)pos;
+		return PTR_TO_UINT64(pos);
 	}
 
 	if (node_up (pos)) {
@@ -205,7 +205,7 @@ static int cmd_indent (int argc, char **
 		}
 		node_remove (node_down (pos));
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
@@ -221,7 +221,7 @@ void init_outdent_indent ()
 				  "moves the active item and the following siblings one level to the right");
 }
 
-static int remove_cmd (int argc, char **argv, void *data)
+static uint64_t remove_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -242,7 +242,7 @@ static int remove_cmd (int argc, char **
 		docmd (pos, "save_state");
 		pos = node_remove (pos);
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
@@ -256,7 +256,7 @@ void init_remove ()
 }
 
 
-static int commandline_cmd (int argc, char **argv, void *data)
+static uint64_t commandline_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -271,7 +271,7 @@ static int commandline_cmd (int argc, ch
 		if (commandline[0])
 			pos = docmd (pos, commandline);
 	} while (commandline[0] && strcmp(commandline,"q") && strcmp(commandline,"quit"));
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
@@ -284,7 +284,7 @@ void init_commandline ()
 				  "Invokes the interactive commandline in curses mode.");
 }
 
-static int insert_below_cmd (int argc, char **argv, void *data)
+static uint64_t insert_below_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -299,7 +299,7 @@ static int insert_below_cmd (int argc, c
 			}
 	}
 	inputbuf[0] = 0;
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
