$NetBSD: patch-src_plugins_render_stars_StarsPlugin.cpp,v 1.1 2013/06/24 06:52:52 jperkin Exp $

Avoid 'sun' clash.

--- src/plugins/render/stars/StarsPlugin.cpp.orig	2013-05-03 04:38:26.039168883 +0000
+++ src/plugins/render/stars/StarsPlugin.cpp
@@ -23,6 +23,8 @@
 #include "SunLocator.h"
 #include "ViewportParams.h"
 
+#undef sun
+
 namespace Marble
 {
 
