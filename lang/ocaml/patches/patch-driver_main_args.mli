$NetBSD: patch-driver_main_args.mli,v 1.4 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- driver/main_args.mli.orig	2016-04-25 13:36:01.000000000 +0000
+++ driver/main_args.mli
@@ -82,6 +82,7 @@ module type Compiler_options = sig
   val _output_obj : unit -> unit
   val _output_complete_obj : unit -> unit
   val _pack : unit -> unit
+  val _pkgsrc_runtime : unit -> unit
   val _pp : string -> unit
   val _principal : unit -> unit
   val _no_principal : unit -> unit
