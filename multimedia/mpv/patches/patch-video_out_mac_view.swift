$NetBSD: patch-video_out_mac_view.swift,v 1.1 2026/11/12 17:18:06 leot Exp $

Fix build on macOS when Vulkan is disabled.

Shared upstream via <https://github.com/mpv-player/mpv/pull/18818>,
should fix <https://github.com/mpv-player/mpv/issues/18817>.

--- video/out/mac/view.swift.orig	2026-11-04 23:33:41.000000000 +0000
+++ video/out/mac/view.swift
@@ -29,7 +29,7 @@ class View: NSView, CALayerDelegate {
     override var acceptsFirstResponder: Bool { return true }
 
     override var isOpaque: Bool {
-        if let metalLayer = layer as? MetalLayer {
+        if let metalLayer = layer as? CAMetalLayer {
             return !metalLayer.isOpaque
         }
 
