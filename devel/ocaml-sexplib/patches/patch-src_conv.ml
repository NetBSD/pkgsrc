$NetBSD: patch-src_conv.ml,v 1.1 2016/06/20 15:10:30 jaapb Exp $

Changes for ocaml 4.03 (patch from upstream)
--- src/conv.ml.orig	2016-04-28 09:46:25.000000000 +0000
+++ src/conv.ml
@@ -185,7 +185,7 @@ module Exn_converter = struct
 
   (* [Obj.extension_id] works on both the exception itself, and the extension slot of the
      exception. *)
-  let rec clean_up_handler (slot : Obj.t) =
+  let rec clean_up_handler (slot : extension_constructor) =
     let id = Obj.extension_id slot in
     let old_exn_id_map = !exn_id_map in
     let new_exn_id_map = Exn_ids.remove id old_exn_id_map in
@@ -196,7 +196,7 @@ module Exn_converter = struct
       exn_id_map := new_exn_id_map
 
   let add_auto ?(finalise = true) exn sexp_of_exn =
-    let id = Obj.extension_id exn in
+    let id = Obj.extension_id (Obj.extension_constructor exn) in
     let rec loop () =
       let old_exn_id_map = !exn_id_map in
       let new_exn_id_map = Exn_ids.add id sexp_of_exn old_exn_id_map in
@@ -205,13 +205,17 @@ module Exn_converter = struct
         loop ()
       else begin
         exn_id_map := new_exn_id_map;
-        if finalise then Gc.finalise clean_up_handler (Obj.extension_slot exn)
+				if finalise then
+				  try
+					  Gc.finalise clean_up_handler (Obj.extension_constructor exn)
+					with Invalid_argument _ ->
+						()
       end
     in
     loop ()
 
   let find_auto exn =
-    let id = Obj.extension_id exn in
+    let id = Obj.extension_id (Obj.extension_constructor exn) in
     match Exn_ids.find id !exn_id_map with
     | exception Not_found -> None
     | sexp_of_exn -> Some (sexp_of_exn exn)
