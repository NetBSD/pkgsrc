$NetBSD: patch-src_misc_newinstall.cxx,v 1.4 2014/09/05 07:29:28 mef Exp $

Brag command shows OS:, but it is fixed, see SUBST in Makefile

--- src/misc/newinstall.cxx.orig	2012-09-25 13:22:44.000000000 +0900
+++ src/misc/newinstall.cxx	2012-09-25 13:23:42.000000000 +0900
@@ -83,7 +83,7 @@
 Rig:   \n\
 Pwr:   \n\
 Ant:   \n\
-OS:    Linux\n\
+OS:    @@OS@@\n\
 Soft:  <VER>\n\
 Web:   \n\
 Email: ";
