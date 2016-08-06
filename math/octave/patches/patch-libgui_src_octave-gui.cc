$NetBSD: patch-libgui_src_octave-gui.cc,v 1.2 2016/08/06 13:03:35 prlw1 Exp $

Changes for compiling with Qt5 instead of Qt4

--- libgui/src/octave-gui.cc.orig	2016-04-20 18:23:57.000000000 +0000
+++ libgui/src/octave-gui.cc
@@ -92,7 +92,7 @@ private:
 // Disable all Qt messages by default.
 
 static void
-message_handler (QtMsgType, const char *)
+message_handler (QtMsgType, const QMessageLogContext &, const QString &)
 {
 }
 
@@ -108,7 +108,7 @@ octave_start_gui (int argc, char *argv[]
 
   // Installing our handler suppresses the messages.
   if (show_gui_msgs.empty ())
-    qInstallMsgHandler (message_handler);
+    qInstallMessageHandler (message_handler);
 
   install___init_qt___functions ();
 
@@ -119,7 +119,7 @@ octave_start_gui (int argc, char *argv[]
 
   // Set the codec for all strings (before wizard)
 #if ! defined (Q_OS_WIN32)
-  QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("UTF-8"));
+  QTextCodec::setCodecForLocale (QTextCodec::codecForName ("UTF-8"));
 #endif
 
   // show wizard if this is the first run
