$NetBSD: patch-src_search.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/search.c.orig	2003-03-14 02:19:21.000000000 +0000
+++ src/search.c
@@ -28,7 +28,7 @@
 
 /************** search ************************/
 
-static int search(int argc,char **argv,void *data){
+static uint64_t search(int argc,char **argv,void *data){
 	Node *pos=(Node *)data;
 	
 	if(argc==2){
@@ -37,7 +37,7 @@
 			if (pos == NULL) {
 				docmdf (pos, "status 'reached bottom of tree and \\'%s\\' not found'",
 						argv[1]);
-				return (int) data;
+				return PTR_TO_UINT64(data);
 			}			
 		}
 	} else if(argc>2){
@@ -46,20 +46,20 @@
 			if (pos == NULL) {
 				docmdf (pos, "status 'reached top of tree and \\'%s\\' not found'",
 						argv[2]);
-				return (int) data;
+				return PTR_TO_UINT64(data);
 			}			
 		} else if(!strcmp(argv[1],"-f")){
 			pos=node_recursive_match( argv[2],pos);
 			if (pos == NULL) {
 				docmdf (pos, "status 'reached bottom of tree and \\'%s\\' not found'",
 						argv[2]);
-				return (int) data;
+				return PTR_TO_UINT64(data);
 			}
 		}
-		return (int)pos;
+		return PTR_TO_UINT64(pos);
 	} 
 	cli_outfunf("usage: %s [-b|-f] <string>",argv[0]);
-	return (int)pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
