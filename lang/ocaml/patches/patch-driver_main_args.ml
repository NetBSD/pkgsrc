$NetBSD: patch-driver_main_args.ml,v 1.3 2015/12/29 23:34:53 dholland Exp $

pkgsrc_runtime flag

--- driver/main_args.ml.orig	2015-05-12 15:31:26.000000000 +0000
+++ driver/main_args.ml
@@ -244,6 +244,10 @@ let mk_pack_opt f =
   "-pack", Arg.Unit f, " Package the given .cmx files into one .cmx"
 ;;
 
+let mk_pkgsrc_runtime f =
+  "-pkgsrc-runtime", Arg.Unit f, " Use pkgsrc linking for runtime"
+;;
+
 let mk_pp f =
   "-pp", Arg.String f, "<command>  Pipe sources through preprocessor <command>"
 ;;
@@ -537,6 +541,7 @@ module type Compiler_options = sig
   val _output_obj : unit -> unit
   val _output_complete_obj : unit -> unit
   val _pack : unit -> unit
+  val _pkgsrc_runtime : unit -> unit
   val _pp : string -> unit
   val _principal : unit -> unit
   val _rectypes : unit -> unit
@@ -689,6 +694,7 @@ struct
     mk_output_obj F._output_obj;
     mk_output_complete_obj F._output_complete_obj;
     mk_pack_byt F._pack;
+    mk_pkgsrc_runtime F._pkgsrc_runtime;
     mk_pp F._pp;
     mk_ppx F._ppx;
     mk_principal F._principal;
@@ -807,6 +813,7 @@ struct
     mk_output_complete_obj F._output_complete_obj;
     mk_p F._p;
     mk_pack_opt F._pack;
+    mk_pkgsrc_runtime F._pkgsrc_runtime;
     mk_pp F._pp;
     mk_ppx F._ppx;
     mk_principal F._principal;
