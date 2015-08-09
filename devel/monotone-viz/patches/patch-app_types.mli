$NetBSD: patch-app_types.mli,v 1.1 2015/08/09 13:21:42 jaapb Exp $

Moved classes to separate module for ocaml 4.02.
--- /dev/null	2015-08-09 12:54:30.000000000 +0000
+++ app_types.mli
@@ -0,0 +1,51 @@
+class type status = 
+  object
+    method push           : string -> unit
+    method pop            : unit -> unit
+    method progress_start : string -> int -> unit
+    method progress       : int -> unit
+    method progress_end   : unit -> unit
+    method with_status    : string -> (unit -> 'a) -> 'a
+  end
+
+class type t =
+    object
+      method get_mtn : Monotone.t option
+      method get_agraph : Agraph.t option
+      method get_prefs : Viz_style.prefs
+      method get_toplevel : GWindow.window
+
+      method set_prefs : Viz_style.prefs -> unit
+
+      method open_db : ?id:string -> ?branch:string -> string -> unit
+      method close_db : unit -> unit
+      method finalize  : unit -> unit
+      method display_certs : string -> unit
+      method focus_find_entry : unit -> unit
+      method get_current_cert_value : string option 
+      method reload : unit -> unit
+      method zoom_in : unit -> unit
+      method zoom_out : unit -> unit
+      method re_layout : unit -> unit
+      method redraw : unit -> unit
+      method query : Viz_types.select_info -> unit
+      method get_selected_node : string option
+      method find : string -> unit
+      method switch_branch : string * string -> unit
+      method update_begin : unit
+      method update_end : unit
+      method center_on :string * Viz_types.c_node -> unit
+      method center_on_by_id : string -> unit
+      method view_popup : string * int -> unit
+      method cert_popup : int -> unit
+
+      method show_open : unit -> unit
+      method show_view : unit -> unit
+      method show_search : unit -> unit
+      method show_prefs : unit -> unit
+      method show_diff : string -> string -> unit
+
+      method status : string -> status
+
+      method error_notice : string -> unit
+    end
