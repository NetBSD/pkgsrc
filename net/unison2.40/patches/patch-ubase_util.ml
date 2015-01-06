$NetBSD: patch-ubase_util.ml,v 1.1 2015/01/06 12:57:03 wiz Exp $

Fix incompatibility with ocaml-4.02.x, based on
http://caml.inria.fr/mantis/view.php?id=6621

--- ubase/util.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ ubase/util.ml
@@ -62,7 +62,7 @@ let set_infos s =
   if s <> !infos then begin clear_infos (); infos := s; show_infos () end
 
 let msg f =
-  clear_infos (); Uprintf.eprintf (fun () -> flush stderr; show_infos ()) f
+  clear_infos (); Printf.kfprintf (fun c -> flush c; show_infos ()) stderr f
 
 let msg : ('a, out_channel, unit) format -> 'a = msg
 
