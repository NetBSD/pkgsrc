$NetBSD: patch-ui.mli,v 1.1 2015/08/09 13:21:42 jaapb Exp $

Moved classes to separate module for ocaml 4.02.
--- ui.mli.orig	2007-03-07 21:53:54.000000000 +0000
+++ ui.mli
@@ -26,37 +26,37 @@ val category :
 class status_bar :
   packing:(GObj.widget -> unit) ->
   string ->
-  App.status
+  App_types.status
 
 module Prefs : sig
   val update_prefs :
-    #App.t ->
+    #App_types.t ->
     Viz_style.prefs -> Viz_style.prefs -> unit
-  val show : #App.t -> unit -> unit
+  val show : #App_types.t -> unit -> unit
 end
 
 module Open : sig
   type t
-  val make : #App.t -> t
+  val make : #App_types.t -> t
   val show : t -> string option
 end
 
 (*
 module LockedDB : sig
-  val show : #App.t -> [`FAIL | `RETRY]
+  val show : #App_types.t -> [`FAIL | `RETRY]
 end
 *)
 
 type manager
 val make  : unit -> manager * GObj.widget * GObj.widget
-val setup : manager -> #App.t -> unit
+val setup : manager -> #App_types.t -> unit
 
 val popup :
-  manager -> #App.t ->
+  manager -> #App_types.t ->
   popup_id:string -> int -> unit
 val popup_cert : manager -> int -> unit
-val open_db    : manager -> #App.t -> unit
-val close_db   : manager -> #App.t -> unit
+val open_db    : manager -> #App_types.t -> unit
+val close_db   : manager -> #App_types.t -> unit
 val clear      : manager -> unit
 val update_begin : manager -> unit
 
