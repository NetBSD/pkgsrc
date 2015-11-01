$NetBSD: patch-modules_gui_qt4_dialogs_messages.cpp,v 1.1 2015/11/01 20:15:06 tnn Exp $

Fix build with clang. &this->verbosity is unsigned.

--- modules/gui/qt4/dialogs/messages.cpp.orig	2014-11-16 18:57:59.000000000 +0000
+++ modules/gui/qt4/dialogs/messages.cpp
@@ -143,7 +143,7 @@ MessagesDialog::~MessagesDialog()
 
 void MessagesDialog::changeVerbosity( int i_verbosity )
 {
-    atomic_store( &this->verbosity, i_verbosity );
+    atomic_store( &this->verbosity, (unsigned int)i_verbosity );
 }
 
 void MessagesDialog::updateConfig()
