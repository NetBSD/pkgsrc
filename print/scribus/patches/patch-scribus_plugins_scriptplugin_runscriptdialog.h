$NetBSD: patch-scribus_plugins_scriptplugin_runscriptdialog.h,v 1.1 2013/01/15 15:28:37 joerg Exp $

--- scribus/plugins/scriptplugin/runscriptdialog.h.orig	2013-01-14 12:21:57.000000000 +0000
+++ scribus/plugins/scriptplugin/runscriptdialog.h
@@ -20,7 +20,7 @@ class RunScriptDialog : public QFileDial
 	Q_OBJECT
 
 	public:
-		RunScriptDialog(QWidget* parent, bool extEnable);
+		RunScriptDialog(QWidget* parent = 0, bool extEnable = false);
 		~RunScriptDialog();
 
 		/// Check if the user wanted the script run as an extension script
