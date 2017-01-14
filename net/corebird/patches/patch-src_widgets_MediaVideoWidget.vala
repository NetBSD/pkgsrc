$NetBSD: patch-src_widgets_MediaVideoWidget.vala,v 1.1 2017/01/14 09:28:41 ryoon Exp $

Fix --disable-video build
from upstream:
https://github.com/baedert/corebird/commit/1718570443777125de6347d4fd1721c68fe67bf2#diff-fbbcc65d4fd928071622b189ff5cf7dd

--- src/widgets/MediaVideoWidget.vala.orig	2017-01-06 15:03:14.000000000 +0000
+++ src/widgets/MediaVideoWidget.vala
@@ -79,6 +79,7 @@ class MediaVideoWidget : Gtk.Stack {
   }
 
   private bool progress_timeout_cb () {
+#if VIDEO
     int64 duration_ns;
     int64 position_ns;
 
@@ -88,6 +89,7 @@ class MediaVideoWidget : Gtk.Stack {
       double fraction = (double) position_ns / (double) duration_ns;
       this.video_progress.set_fraction (fraction);
     }
+#endif
 
     return GLib.Source.CONTINUE;
   }
