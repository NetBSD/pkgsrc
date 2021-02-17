$NetBSD: patch-base_password__manager.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- base/password_manager.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ base/password_manager.cc
@@ -264,7 +264,7 @@ bool WinMacPasswordManager::RemovePasswo
 // We use plain text file for password storage on Linux. If you port this module
 // to other Linux distro, you might want to implement a new password manager
 // which adopts some secure mechanism such like gnome-keyring.
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
 typedef PlainPasswordManager DefaultPasswordManager;
 #endif  // OS_LINUX || OS_ANDROID || OS_WASM
 
