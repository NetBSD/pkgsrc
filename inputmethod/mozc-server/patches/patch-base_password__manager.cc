$NetBSD: patch-base_password__manager.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- base/password_manager.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/password_manager.cc
@@ -366,7 +366,7 @@ class DeprecatedMacPasswordManager : pub
 // this module to other Linux distro, you might want to implement
 // a new password manager which adopts some secure mechanism such
 // like gnome-keyring.
-#if defined OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 typedef PlainPasswordManager DefaultPasswordManager;
 #endif
 
