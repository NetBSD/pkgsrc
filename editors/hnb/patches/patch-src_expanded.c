$NetBSD: patch-src_expanded.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/expanded.c.orig	2003-03-13 21:31:18.000000000 +0000
+++ src/expanded.c
@@ -18,16 +18,18 @@
  * Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <string.h>
+
 #include "tree.h"
 #include "cli.h"
-#define NULL 0
+//#define NULL 0
 
 #include "evilloop.h"
 #include "ctype.h"
 #include "ui_binding.h"
 
 
-static int cmd_expand (int argc,char **argv, void *data)
+static uint64_t cmd_expand (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	if(argc==1){
@@ -36,7 +36,7 @@
 				inputbuf[strlen (inputbuf) + 1] = 0;
 				inputbuf[strlen (inputbuf)] = lastbinding->key;
 			}
-			return (int)pos;
+			return PTR_TO_UINT64(pos);
 		}
 		node_setflag(pos,F_expanded,1);
 	} else if((!strcmp(argv[1],"-a"))||(!strcmp(argv[1],"--all"))){
@@ -48,10 +48,10 @@
 		}
 		cli_outfun ("expanded all nodes");
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int cmd_collapse (int argc,char **argv, void *data)
+static uint64_t cmd_collapse (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	if(argc==1){
@@ -60,7 +60,7 @@
 				inputbuf[strlen (inputbuf) + 1] = 0;
 				inputbuf[strlen (inputbuf)] = lastbinding->key;
 			}		
-			return (int)pos;
+			return PTR_TO_UINT64(pos);
 		}
 		node_setflag(pos,F_expanded,0);
 	} else if((!strcmp(argv[1],"-a"))||(!strcmp(argv[1],"--all"))){
@@ -73,7 +73,7 @@
 		cli_outfun ("collapsed all nodes");
 	}
 	
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
