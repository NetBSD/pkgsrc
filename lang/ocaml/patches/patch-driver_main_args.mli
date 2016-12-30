$NetBSD: patch-driver_main_args.mli,v 1.5 2016/12/30 11:15:00 jaapb Exp $

pkgsrc_runtime flag

--- driver/main_args.mli.orig	2016-09-05 13:19:52.000000000 +0000
+++ driver/main_args.mli
@@ -84,6 +84,7 @@ module type Compiler_options = sig
   val _output_obj : unit -> unit
   val _output_complete_obj : unit -> unit
   val _pack : unit -> unit
+  val _pkgsrc_runtime : unit -> unit
   val _plugin : string -> unit
   val _pp : string -> unit
   val _principal : unit -> unit
