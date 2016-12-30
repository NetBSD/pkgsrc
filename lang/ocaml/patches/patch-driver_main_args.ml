$NetBSD: patch-driver_main_args.ml,v 1.5 2016/12/30 11:15:00 jaapb Exp $

pkgsrc_runtime flag

--- driver/main_args.ml.orig	2016-09-05 13:19:52.000000000 +0000
+++ driver/main_args.ml
@@ -376,6 +376,10 @@ let mk_pack_opt f =
   "-pack", Arg.Unit f, " Package the given .cmx files into one .cmx"
 ;;
 
+let mk_pkgsrc_runtime f =
+  "-pkgsrc-runtime", Arg.Unit f, " Use pkgsrc linking for runtime"
+;;
+
 let mk_pp f =
   "-pp", Arg.String f, "<command>  Pipe sources through preprocessor <command>"
 ;;
@@ -797,6 +801,7 @@ module type Compiler_options = sig
   val _output_obj : unit -> unit
   val _output_complete_obj : unit -> unit
   val _pack : unit -> unit
+	val _pkgsrc_runtime : unit -> unit
   val _plugin : string -> unit
   val _pp : string -> unit
   val _principal : unit -> unit
@@ -988,6 +993,7 @@ struct
     mk_output_obj F._output_obj;
     mk_output_complete_obj F._output_complete_obj;
     mk_pack_byt F._pack;
+		mk_pkgsrc_runtime F._pkgsrc_runtime;
     mk_pp F._pp;
     mk_ppx F._ppx;
     mk_plugin F._plugin;
@@ -1148,6 +1154,7 @@ struct
     mk_output_complete_obj F._output_complete_obj;
     mk_p F._p;
     mk_pack_opt F._pack;
+		mk_pkgsrc_runtime F._pkgsrc_runtime;
     mk_plugin F._plugin;
     mk_pp F._pp;
     mk_ppx F._ppx;
