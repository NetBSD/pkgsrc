$NetBSD: patch-src_cli__macro.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/cli_macro.c.orig	2003-03-09 20:44:27.000000000 +0000
+++ src/cli_macro.c
@@ -80,7 +80,7 @@
 	return pos;
 }
 
-static int cmd_macro (int argc, char **argv, void *data)
+static uint64_t cmd_macro (int argc, char **argv, void *data)
 {
 	Node *pos=(Node *)data;
 	if(argc==1){
@@ -88,7 +88,7 @@
 	} else if(argc==2){
 		MacroT *tmacro=lookup_macro(argv[1]);
 		if(tmacro){
-			return (int)do_macro(tmacro,pos);
+			return PTR_TO_UINT64(do_macro(tmacro,pos));
 		} else {
 			cli_outfunf("no such macro defined '%s'",argv[1]);
 		}
@@ -97,7 +97,7 @@
 		if(!strcmp(argv[1],"define") ){
 			if(lookup_macro(argv[2])){
 				cli_outfunf("error macro %s already exist,.. this might turn out badly,.. " ,argv[2]);
-				return (int) pos;
+				return PTR_TO_UINT64(pos);
 			} else {
 				MacroT *tmacro;
 				if(!macro){
@@ -119,7 +119,7 @@
 			
 		}
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 
