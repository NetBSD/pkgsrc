$NetBSD: patch-driver_main_args.mli,v 1.1 2015/01/20 14:12:25 jaapb Exp $

pkgsrc_runtime flag
--- driver/main_args.mli.orig	2014-09-26 13:00:20.000000000 +0000
+++ driver/main_args.mli
@@ -68,6 +68,7 @@ module type Compiler_options =  sig
   val _o : string -> unit
   val _output_obj : unit -> unit
   val _pack : unit -> unit
+	val _pkgsrc_runtime : unit -> unit
   val _pp : string -> unit
   val _principal : unit -> unit
   val _rectypes : unit -> unit
