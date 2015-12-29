$NetBSD: patch-driver_main_args.mli,v 1.3 2015/12/29 23:34:53 dholland Exp $

pkgsrc_runtime flag

--- driver/main_args.mli.orig	2015-05-12 15:31:26.000000000 +0000
+++ driver/main_args.mli
@@ -70,6 +70,7 @@ module type Compiler_options =  sig
   val _output_obj : unit -> unit
   val _output_complete_obj : unit -> unit
   val _pack : unit -> unit
+  val _pkgsrc_runtime : unit -> unit
   val _pp : string -> unit
   val _principal : unit -> unit
   val _rectypes : unit -> unit
