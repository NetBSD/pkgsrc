$NetBSD: patch-view.mli,v 1.1 2015/08/09 13:21:42 jaapb Exp $

Moved classes to separate module for ocaml 4.02.
--- view.mli.orig	2007-03-07 21:53:54.000000000 +0000
+++ view.mli
@@ -1,7 +1,7 @@
 module Info_Display :
   sig
     type t
-    val fetch_and_display_data : t -> #App.t -> string -> unit
+    val fetch_and_display_data : t -> #App_types.t -> string -> unit
     val get_current_cert_value : t -> string option
   end
 
@@ -10,23 +10,23 @@ module Branch_selector :
     type t
     type state
     val get_state  : t -> state
-    val set_state  : t -> #App.t -> ?id:string -> state -> unit
-    val set_branch : t -> #App.t -> ?id:string -> string -> unit
+    val set_state  : t -> #App_types.t -> ?id:string -> state -> unit
+    val set_branch : t -> #App_types.t -> ?id:string -> string -> unit
     val present_dialog : t -> unit
   end
 
 module Canvas :
   sig
     type t
-    val zoom : t -> #App.t -> [< `IN | `OUT ] -> unit -> unit
-    val id_size : t -> #App.t -> int * int * int
-    val center_on : t -> #App.t -> string * Viz_types.c_node -> unit
+    val zoom : t -> #App_types.t -> [< `IN | `OUT ] -> unit -> unit
+    val id_size : t -> #App_types.t -> int * int * int
+    val center_on : t -> #App_types.t -> string * Viz_types.c_node -> unit
   end
 
 module Find :
   sig
     type t
-    val locate : t -> #App.t -> string -> unit
+    val locate : t -> #App_types.t -> string -> unit
     val focus_find_entry : t -> unit
   end
 
@@ -42,10 +42,10 @@ val make : 
   parent:#GWindow.window_skel ->
   pack_find_entry:(GObj.widget -> unit) ->
   pack_canvas:(GObj.widget -> unit) -> t
-val setup : t -> #App.t -> unit
+val setup : t -> #App_types.t -> unit
 
-val clear    : t -> #App.t -> unit
-val close_db : t -> #App.t -> unit
-val open_db  : t -> #App.t -> unit
-val update   : t -> #App.t -> string option -> unit
+val clear    : t -> #App_types.t -> unit
+val close_db : t -> #App_types.t -> unit
+val open_db  : t -> #App_types.t -> unit
+val update   : t -> #App_types.t -> string option -> unit
 val get_selected_node : t -> string option
