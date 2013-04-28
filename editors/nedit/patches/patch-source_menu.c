$NetBSD: patch-source_menu.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Call XtVaGetValues correctly.

--- source/menu.c~	2004-09-15 22:50:57.000000000 +0000
+++ source/menu.c
@@ -1242,7 +1242,7 @@ static Widget makeHelpMenuItem(
     Widget menuItem = 
         createMenuItem( parent, name, label, mnemonic, callback, cbArg, mode );
     
-    XtVaSetValues( menuItem, XmNuserData, topic, 0 );
+    XtVaSetValues( menuItem, XmNuserData, topic, (char *)NULL);
     return menuItem;
 }
 
@@ -1254,7 +1254,7 @@ static void helpCB( Widget menuItem, XtP
     
     HidePointerOnKeyedEvent(WidgetToWindow(MENU_WIDGET(menuItem))->lastFocus,
             ((XmAnyCallbackStruct *)callData)->event);
-    XtVaGetValues( menuItem, XmNuserData, &topic, 0 );
+    XtVaGetValues( menuItem, XmNuserData, &topic, (char *)NULL);
     
     Help(topic);
 }
