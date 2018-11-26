$NetBSD: patch-src_ui__menu.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/ui_menu.c.orig	2003-03-14 03:54:52.000000000 +0000
+++ src/ui_menu.c
@@ -109,10 +109,10 @@ static Node *menu_do(Node *pos){
 	return pos;
 }
 
-static int cmd_menu(int argc,char **argv,void *data){
+static uint64_t cmd_menu(int argc,char **argv,void *data){
 	Node *pos=(Node *)data;
 	if(argc==1){ /* draw menu */
-		return (int)menu_do(pos);
+		return PTR_TO_UINT64(menu_do(pos));
 	} else if(argc==4){
 		char *submenu=argv[1];
 		char *label=argv[2];
@@ -142,7 +142,7 @@
 		if(menu[col][row].width>menu[col][0].width)
 			menu[col][0].width=menu[col][row].width;	
 	}
-	return(int)pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
