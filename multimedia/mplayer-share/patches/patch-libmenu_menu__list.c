$NetBSD: patch-libmenu_menu__list.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- libmenu/menu_list.c.orig	2025-10-08 03:54:48.548403463 +0000
+++ libmenu/menu_list.c
@@ -274,7 +274,7 @@ void menu_list_read_cmd(menu_t* menu,int
 }
 
 int menu_list_jump_to_key(menu_t* menu,int c) {
-  if(c < 256 && isalnum(c)) {
+  if(c < 256 && isalnum((unsigned char)c)) {
     list_entry_t* e = mpriv->current;
     if(e->txt[0] == c) e = e->next;
     for(  ; e ; e = e->next) {
