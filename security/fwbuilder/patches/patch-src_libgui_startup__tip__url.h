$NetBSD: patch-src_libgui_startup__tip__url.h,v 1.1 2017/06/17 19:52:13 joerg Exp $

Avoid User Defined Literals.

--- src/libgui/startup_tip_url.h.orig	2017-06-10 17:39:29.007229821 +0000
+++ src/libgui/startup_tip_url.h
@@ -29,7 +29,7 @@
 
 #include "../../VERSION.h"
 
-#define STARTUP_TIP_URL "http://update.fwbuilder.org/tips/gettip.cgi?v="VERSION
+#define STARTUP_TIP_URL "http://update.fwbuilder.org/tips/gettip.cgi?v=" VERSION
 
 #endif
 
