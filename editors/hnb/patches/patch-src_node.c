$NetBSD: patch-src_node.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/node.c.orig	2003-03-09 17:33:35.000000000 +0000
+++ src/node.c
@@ -138,48 +138,48 @@
 #include <stdio.h>
 
 
-int cmd_att_set (int argc, char **argv, void *data)
+uint64_t cmd_att_set (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
 	if(argc!=3){
 		cli_outfunf("usage: %s <attribute> <value>",argv[0]);
-		return (int) pos;
+		return PTR_TO_UINT64(pos);
 	}
 		
 	node_set (pos, argv[1], argv[2]);
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-int cmd_att_get (int argc, char **argv, void *data)
+uint64_t cmd_att_get (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	char *cdata;
 	
 	if(argc!=2){
 		cli_outfunf("usage: %s <attribute>",argv[0]);
-		return (int) pos;
+		return PTR_TO_UINT64(pos);
 	}
 			
 	cdata = node_get (pos, argv[1]);
 
 	if (cdata)
 		cli_outfun (cdata);
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-int cmd_att_clear (int argc, char **argv, void *data)
+uint64_t cmd_att_clear (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	if(argc!=2){
 		cli_outfunf("usage: %s <attribute>",argv[0]);
-		return (int) pos;
+		return PTR_TO_UINT64(pos);
 	}
 	node_unset (pos, argv[1]);
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-int cmd_att_list (int argc,char **argv, void *data)
+uint64_t cmd_att_list (int argc,char **argv, void *data)
 {
 	Node_AttItem *att;
 	Node *pos = (Node *) data;
@@ -189,7 +189,7 @@ int cmd_att_list (int argc,char **argv, 
 		cli_outfunf ("%s: [%s]", att->name, att->data);
 		att = att->next;
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
