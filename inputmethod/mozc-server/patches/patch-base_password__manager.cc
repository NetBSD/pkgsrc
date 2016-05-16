$NetBSD: patch-base_password__manager.cc,v 1.3 2016/05/16 11:51:49 ryoon Exp $

--- base/password_manager.cc.orig	2016-05-15 08:11:10.000000000 +0000
+++ base/password_manager.cc
@@ -264,9 +264,9 @@ bool WinMacPasswordManager::RemovePasswo
 // We use plain text file for password storage on Linux. If you port this module
 // to other Linux distro, you might want to implement a new password manager
 // which adopts some secure mechanism such like gnome-keyring.
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
 typedef PlainPasswordManager DefaultPasswordManager;
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 
 // Windows or Mac
 #if (defined(OS_WIN) || defined(OS_MACOSX))
