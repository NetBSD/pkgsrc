$NetBSD: patch-plugins_actions_documentmanagement_documentmanagement.cc,v 1.1 2015/11/03 19:04:57 joerg Exp $

--- plugins/actions/documentmanagement/documentmanagement.cc.orig	2015-11-03 12:10:06.000000000 +0000
+++ plugins/actions/documentmanagement/documentmanagement.cc
@@ -167,7 +167,7 @@ public:
 
 		ui_id = ui->new_merge_id();
 
-		#define ADD_UI(name)	ui->add_ui(ui_id, "/menubar/menu-file/"name, name, name);
+		#define ADD_UI(name)	ui->add_ui(ui_id, "/menubar/menu-file/" name, name, name);
 		
 		ADD_UI("new-document");
 		ADD_UI("open-document");
