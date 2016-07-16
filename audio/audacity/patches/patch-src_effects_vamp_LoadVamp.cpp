$NetBSD: patch-src_effects_vamp_LoadVamp.cpp,v 1.1 2016/07/16 01:32:51 markd Exp $

gcc6 fix

--- src/effects/vamp/LoadVamp.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/effects/vamp/LoadVamp.cpp
@@ -266,7 +266,7 @@ Plugin *VampEffectsModule::FindPlugin(co
    Plugin *vp = PluginLoader::getInstance()->loadPlugin(key, 48000); // rate doesn't matter here
    if (!vp)
    {
-      return false;
+      return NULL;
    }
 
    // We limit the listed plugin outputs to those whose results can
