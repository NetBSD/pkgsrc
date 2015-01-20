$NetBSD: patch-driver_main_args.ml,v 1.1 2015/01/20 14:12:25 jaapb Exp $

pkgsrc_runtime flag
--- driver/main_args.ml.orig	2014-09-26 13:00:20.000000000 +0000
+++ driver/main_args.ml
@@ -231,6 +231,10 @@ let mk_pack_opt f =
   "-pack", Arg.Unit f, " Package the given .cmx files into one .cmx"
 ;;
 
+let mk_pkgsrc_runtime f =
+  "-pkgsrc-runtime", Arg.Unit f, " Use pkgsrc linking for runtime"
+;;
+
 let mk_pp f =
   "-pp", Arg.String f, "<command>  Pipe sources through preprocessor <command>"
 ;;
@@ -522,6 +526,7 @@ module type Compiler_options = sig
   val _o : string -> unit
   val _output_obj : unit -> unit
   val _pack : unit -> unit
+  val _pkgsrc_runtime : unit -> unit
   val _pp : string -> unit
   val _principal : unit -> unit
   val _rectypes : unit -> unit
@@ -669,6 +674,7 @@ struct
     mk_open F._open;
     mk_output_obj F._output_obj;
     mk_pack_byt F._pack;
+    mk_pkgsrc_runtime F._pkgsrc_runtime;
     mk_pp F._pp;
     mk_ppx F._ppx;
     mk_principal F._principal;
@@ -785,6 +791,7 @@ struct
     mk_output_obj F._output_obj;
     mk_p F._p;
     mk_pack_opt F._pack;
+    mk_pkgsrc_runtime F._pkgsrc_runtime;
     mk_pp F._pp;
     mk_ppx F._ppx;
     mk_principal F._principal;
