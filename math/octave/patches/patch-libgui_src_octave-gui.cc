$NetBSD: patch-libgui_src_octave-gui.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

Changes for compiling with Qt5 instead of Qt4

--- libgui/src/octave-gui.cc.orig	2015-05-23 14:21:54.000000000 +0000
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
 
@@ -117,11 +117,6 @@ octave_start_gui (int argc, char *argv[]
   QApplication application (argc, argv);
   QTranslator gui_tr, qt_tr, qsci_tr;
 
-  // Set the codec for all strings (before wizard)
-#if ! defined (Q_OS_WIN32)
-  QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("UTF-8"));
-#endif
-
   if (start_gui)
     {
       // show wizard if this is the first run
