$NetBSD: patch-base_password__manager.cc,v 1.2 2014/01/19 01:18:50 ryoon Exp $

--- base/password_manager.cc.orig	2014-01-06 07:10:31.000000000 +0000
+++ base/password_manager.cc
@@ -264,7 +264,7 @@ bool WinMacPasswordManager::RemovePasswo
 // We use plain text file for password storage on Linux. If you port this module
 // to other Linux distro, you might want to implement a new password manager
 // which adopts some secure mechanism such like gnome-keyring.
-#if defined OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 typedef PlainPasswordManager DefaultPasswordManager;
 #endif
 
