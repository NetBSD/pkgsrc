$NetBSD: patch-driver_main_args.ml,v 1.4 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- driver/main_args.ml.orig	2016-04-25 13:36:01.000000000 +0000
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
@@ -767,6 +771,7 @@ module type Compiler_options = sig
   val _output_obj : unit -> unit
   val _output_complete_obj : unit -> unit
   val _pack : unit -> unit
+  val _pkgsrc_runtime : unit -> unit
   val _pp : string -> unit
   val _principal : unit -> unit
   val _no_principal : unit -> unit
@@ -955,6 +960,7 @@ struct
     mk_output_obj F._output_obj;
     mk_output_complete_obj F._output_complete_obj;
     mk_pack_byt F._pack;
+    mk_pkgsrc_runtime F._pkgsrc_runtime;
     mk_pp F._pp;
     mk_ppx F._ppx;
     mk_principal F._principal;
@@ -1108,6 +1114,7 @@ struct
     mk_output_complete_obj F._output_complete_obj;
     mk_p F._p;
     mk_pack_opt F._pack;
+    mk_pkgsrc_runtime F._pkgsrc_runtime;
     mk_pp F._pp;
     mk_ppx F._ppx;
     mk_principal F._principal;
