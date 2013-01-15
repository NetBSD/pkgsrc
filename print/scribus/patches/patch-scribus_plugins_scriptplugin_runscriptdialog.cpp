$NetBSD: patch-scribus_plugins_scriptplugin_runscriptdialog.cpp,v 1.1 2013/01/15 15:28:37 joerg Exp $

--- scribus/plugins/scriptplugin/runscriptdialog.cpp.orig	2013-01-14 12:19:58.000000000 +0000
+++ scribus/plugins/scriptplugin/runscriptdialog.cpp
@@ -11,7 +11,7 @@ for which a new license (GPL+exception) 
 
 QString RunScriptDialog::m_lastScriptDir;
 
-RunScriptDialog::RunScriptDialog(QWidget* parent = 0, bool extEnable = false) :
+RunScriptDialog::RunScriptDialog(QWidget* parent, bool extEnable) :
 	QFileDialog(parent, "runScriptDialog", true)
 {
 	this->extEnable = extEnable;
