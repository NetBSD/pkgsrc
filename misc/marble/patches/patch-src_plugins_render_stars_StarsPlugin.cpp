$NetBSD: patch-src_plugins_render_stars_StarsPlugin.cpp,v 1.2 2014/11/13 19:19:06 markd Exp $

Avoid 'sun' clash.

--- src/plugins/render/stars/StarsPlugin.cpp.orig	2014-10-23 21:53:08.000000000 +0000
+++ src/plugins/render/stars/StarsPlugin.cpp
@@ -34,6 +34,8 @@
 
 #include "src/lib/astro/solarsystem.h"
 
+#undef sun
+
 namespace Marble
 {
 
