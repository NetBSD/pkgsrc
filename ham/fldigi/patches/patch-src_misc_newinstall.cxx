$NetBSD: patch-src_misc_newinstall.cxx,v 1.1 2012/09/28 13:41:30 gdt Exp $

Brag command show OS:, but it is fixed, See SUBST in Makefile

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
