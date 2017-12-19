$NetBSD: patch-src_plugins_gui_gtk__helper.ml,v 1.1 2017/12/19 08:17:21 markd Exp $

Glib.Io.read wants bytes so dont convert to string

--- src/plugins/gui/gtk_helper.ml.orig	2017-06-01 08:02:15.000000000 +0000
+++ src/plugins/gui/gtk_helper.ml
@@ -319,9 +319,7 @@ let channel_redirector channel callback
                   (* On Windows, you must use Io.read *)
                   (* buf' is added only to work around the suspicious type of
                      Glib.Io.read *)
-                  let buf' = Bytes.to_string buf in
-                  let len = Glib.Io.read channel ~buf:buf' ~pos:0 ~len in
-                  let buf = Bytes.of_string buf' in
+                  let len = Glib.Io.read channel ~buf:buf ~pos:0 ~len in
                   len >= 1 &&
                   (let full_string = !current_partial ^ Bytes.sub_string buf 0 len in
                    let to_emit, c = splitting_for_utf8 full_string in
