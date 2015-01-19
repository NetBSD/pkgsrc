$NetBSD: patch-Keyboard.h,v 1.1 2015/01/19 20:42:09 jmcneill Exp $

--- Keyboard.h.orig	2015-01-12 15:10:50.000000000 +0000
+++ Keyboard.h
@@ -21,7 +21,7 @@
   void Process();
   void setKeymap(std::map<int,int> keymap);
   void setDbusName(std::string dbus_name);
-  void Sleep(unsigned int dwMilliSeconds);
+  int Hit();
   int getEvent();
  private:
   void restore_term();
