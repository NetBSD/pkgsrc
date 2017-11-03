$NetBSD: patch-ide_ideutils.ml,v 1.1 2017/11/03 11:20:28 jaapb Exp $

For compilation with lablgtk 2.18.6
--- ide/ideutils.ml.orig	2017-10-16 08:53:18.000000000 +0000
+++ ide/ideutils.ml
@@ -373,7 +373,7 @@ let io_read_all chan =
   Buffer.clear read_buffer;
   let read_once () =
     (* XXX: Glib.Io must be converted to bytes / -safe-string upstream *)
-    let len = Glib.Io.read_chars ~buf:(Bytes.unsafe_to_string read_string) ~pos:0 ~len:maxread chan in
+    let len = Glib.Io.read_chars ~buf:read_string ~pos:0 ~len:maxread chan in
     Buffer.add_subbytes read_buffer read_string 0 len
   in
   begin
