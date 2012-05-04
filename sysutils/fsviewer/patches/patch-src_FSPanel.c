$NetBSD: patch-src_FSPanel.c,v 1.1 2012/05/04 16:34:48 joerg Exp $

--- src/FSPanel.c.orig	2012-05-04 13:30:20.000000000 +0000
+++ src/FSPanel.c
@@ -748,7 +748,7 @@ FSRunAppInputPanel(FSViewer *app, FileIn
 {
     char *result = NULL;
 
-    if (!(appInput = FSCreateAppInputPanel(app, fileInfo, title))) { return; }
+    if (!(appInput = FSCreateAppInputPanel(app, fileInfo, title))) { return NULL; }
     
     WMMapWidget(appInput->win);
 
@@ -1205,7 +1205,7 @@ FSRunAlertPanel(FSViewer *app,
 
     if( !(alertPanel = FSCreateAlertPanel(app, title, msg, 
 					  defaultButton, alternateButton, 
-					  otherButton) ) ) {return;}
+					  otherButton) ) ) {return -1;}
 
     WMMapWidget(alertPanel->win);
 
@@ -1392,10 +1392,10 @@ FSRunSelectIconPanel(WMWindow *owner, ch
     char *imgStr = NULL;
 
     if(selIcon)
-	return;
+	return NULL;
 
     if (!(selIcon = FSCreateSelectIconPanel(owner, title, str))) 
-	return;
+	return NULL;
     
     WMMapWidget(selIcon->win);
     
