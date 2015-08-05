$NetBSD: patch-pgadmin_ctl_ctlMenuToolbar.cpp,v 1.1 2015/08/05 15:29:00 richard Exp $
Resolved an assertion error opening the plugin popup menu
for wxWidgets 3.0 (upstream commit b75c57f69e4799507622b8d2f9820cda2bf154a3)
--- pgadmin/ctl/ctlMenuToolbar.cpp.orig	2014-01-27 12:11:43.000000000 +0000
+++ pgadmin/ctl/ctlMenuToolbar.cpp
@@ -109,7 +109,7 @@ void ctlMenuButton::DoProcessLeftClick(w
 		menu_pos.y = button_size.GetHeight();
 	}
 
-	PopupMenu(m_menu, menu_pos);
+	DoPopupMenu(m_menu, menu_pos.x, menu_pos.y);
 }
 
 
