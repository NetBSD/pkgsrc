$NetBSD: patch-simgear_scene_viewer_CompositorPass.hxx,v 1.1 2025/01/31 07:40:48 wiz Exp $

Add missing include.

--- simgear/scene/viewer/CompositorPass.hxx.orig	2025-01-31 07:38:44.149289267 +0000
+++ simgear/scene/viewer/CompositorPass.hxx
@@ -17,6 +17,7 @@
 #ifndef SG_COMPOSITOR_PASS_HXX
 #define SG_COMPOSITOR_PASS_HXX
 
+#include <array>>
 #include <unordered_map>
 
 #include <osg/Camera>
