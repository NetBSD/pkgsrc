$NetBSD: patch-src_editor_message__box.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/editor/message_box.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/editor/message_box.hpp
@@ -45,7 +45,7 @@ public:
   void on_cancel_button();
 
 public:
-  boost::signal<void()> on_ok;
+  boost::signals2::signal<void()> on_ok;
 
 private:
   MessageBox(const MessageBox&);
