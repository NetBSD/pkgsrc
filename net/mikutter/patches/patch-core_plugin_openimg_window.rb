$NetBSD: patch-core_plugin_openimg_window.rb,v 1.1 2018/01/13 04:46:39 tsutsui Exp $

- pull upstream fix
 https://dev.mikutter.hachune.net/issues/1137

--- core/plugin/openimg/window.rb.orig	2017-12-24 15:00:56.000000000 +0000
+++ core/plugin/openimg/window.rb
@@ -20,23 +20,28 @@ module Plugin::Openimg
         if pixbufloader.is_a? GdkPixbuf::PixbufLoader
           rect = nil
           pixbufloader.ssc(:area_updated, self) do |_, x, y, width, height|
-            if rect
-              rect[:left] = [rect[:left], x].min
-              rect[:top] = [rect[:top], y].min
-              rect[:right] = [rect[:right], x+width].max
-              rect[:bottom] = [rect[:bottom], y+height].max
-            else
-              rect = {left: x, top: y, right: x+width, bottom: y+height}
-              Delayer.new do
-                progress(pixbufloader.pixbuf,
-                         x: rect[:left],
-                         y: rect[:top],
-                         width: rect[:right] - rect[:left],
-                         height: rect[:bottom] - rect[:top])
-                rect = nil
+            atomic do
+              if rect
+                rect[:left] = [rect[:left], x].min
+                rect[:top] = [rect[:top], y].min
+                rect[:right] = [rect[:right], x+width].max
+                rect[:bottom] = [rect[:bottom], y+height].max
+              else
+                rect = {left: x, top: y, right: x+width, bottom: y+height}
+                Delayer.new do
+                  atomic do
+                    progress(pixbufloader.pixbuf,
+                             x: rect[:left],
+                             y: rect[:top],
+                             width: rect[:right] - rect[:left],
+                             height: rect[:bottom] - rect[:top])
+                    rect = nil
+                  end
+                end
               end
             end
-            true end
+            true
+          end
 
           complete_promise.next{
             progress(pixbufloader.pixbuf, paint: true)
