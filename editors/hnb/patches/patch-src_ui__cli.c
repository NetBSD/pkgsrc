$NetBSD: patch-src_ui__cli.c,v 1.1 2018/11/26 09:15:53 fox Exp $

In NetBSD-1.6.2, the <stdlib.h> header uses the word bufsize as a
parameter name in a function prototype. The "file.h" header #defines
bufsize to 4096, which leads to a parser error.

Above fix made by rilling on 2005/03/11

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.
3. Replaced (32bit) int references with proper Node * references.

This prevents the segfault on startup in amd64 systems.

--- src/ui_cli.c.orig	2003-03-14 04:55:14.000000000 +0000
+++ src/ui_cli.c
@@ -22,14 +22,15 @@
 #include <config.h>
 #endif
 
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
 #include "tree.h"
 #include "file.h"
 #include "path.h"
 #include "prefs.h"
 #include "cli.h"
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
 #include "ui_cli.h"
 
 
@@ -49,7 +50,7 @@ static char *path_strip (char *path)
 	return path;
 }
 
-static int add (int argc,char **argv, void *data)
+static uint64_t add (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	Node *tnode;
@@ -65,10 +66,10 @@ static int add (int argc,char **argv, vo
 
 	tnode = node_insert_down (node_bottom (pos));
 	node_set (tnode, TEXT, argv[1]);
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int addc (int argc,char **argv, void *data)
+static uint64_t addc (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	Node *tnode;
@@ -81,7 +82,7 @@ static int addc (int argc,char **argv, v
 	tnode = node_exact_match (argv[1], pos);
 	if (!tnode) {
 		cli_outfun ("specified parent not found");
-		return (int) pos;
+		return PTR_TO_UINT64(pos);
 	}
 
 	if (node_right (tnode)) {
@@ -95,30 +95,30 @@
 	else
 		node_set (tnode, TEXT, argv[2]);
 
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int pwd (int argc,char **argv, void *data)
+static uint64_t pwd (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
 	cli_outfun (path_strip (node2path (pos)));
 	cli_outfun ("\n");
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int cd (int argc, char **argv, void *data)
+static uint64_t cd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	Node *tnode = pos;
 
 	if(argc==1){
-		return (int)node_root(pos);
+		return PTR_TO_UINT64(node_root(pos));
 	}
 
 	if (!strcmp (argv[1], "..")){
 		if (node_left (tnode) != 0)
-			return (int) (node_left (tnode));
+			return PTR_TO_UINT64((node_left (tnode)));
 	}
 		
 
@@ -128,11 +129,11 @@ static int cd (int argc, char **argv, vo
 	}
 	if (!tnode) {
 		cli_outfun ("no such node\n");
-		return (int) pos;
+		return PTR_TO_UINT64(pos);
 	}
-	return (int) tnode;
+	return PTR_TO_UINT64(tnode);
 
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 #include <ctype.h>
@@ -151,7 +152,7 @@ static void pre_command (char *commandli
 	}
 }
 
-static int ls (int argc, char **argv, void *data)
+static uint64_t ls (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -188,7 +189,7 @@ static int ls (int argc, char **argv, vo
 			tnode = node_down (tnode);
 		}
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
@@ -216,11 +216,12 @@
 
 Node *docmd (Node *pos, const char *commandline)
 {
-	int ret;
+	Node * ret;
 	char *cmdline = strdup (commandline);
 
-	ret = cli_docmd (cmdline, pos);
+	ret = (Node *)cli_docmd (cmdline, pos);
 	free (cmdline);
+
 	return (Node *) ret;
 }
 
