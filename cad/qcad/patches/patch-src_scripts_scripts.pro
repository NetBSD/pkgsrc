$NetBSD: patch-src_scripts_scripts.pro,v 1.1 2021/09/19 15:35:40 gdt Exp $

Fix upstream makefiles, just like many other patches.

--- src/scripts/scripts.pro.orig	2021-03-08 13:09:33.000000000 +0000
+++ src/scripts/scripts.pro
@@ -7,7 +7,8 @@ HEADERS     = RScriptsPlugin.h
 SOURCES     = RScriptsPlugin.cpp
 DESTDIR     = ../../plugins
 RC_FILE     = scripts.rc
-LIBS        += -l$${RLIBNAME}core
+LIBS        += -L ../core -l$${RLIBNAME}core
+INSTALLS    += target
 
 CONFIG      += resources_big
 
