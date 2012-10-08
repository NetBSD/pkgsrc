$NetBSD: patch-bytecomp_bytelink.ml,v 1.2 2012/10/08 15:05:33 jaapb Exp $

Honour EXTRA_RT_LIBS
--- bytecomp/bytelink.ml.orig	2012-04-16 15:27:42.000000000 +0000
+++ bytecomp/bytelink.ml
@@ -475,7 +475,7 @@ let link_bytecode_as_c ppf tolink outfil
 (* Build a custom runtime *)
 
 let build_custom_runtime prim_name exec_name =
-  let runtime_lib = "-lcamlrun" ^ !Clflags.runtime_variant in
+  let runtime_lib = "-lcamlrun @EXTRA_RT_LIBS@" ^ !Clflags.runtime_variant in
   Ccomp.call_linker Ccomp.Exe exec_name
     ([prim_name] @ List.rev !Clflags.ccobjs @ [runtime_lib])
     (Clflags.std_include_flag "-I" ^ " " ^ Config.bytecomp_c_libraries)
@@ -560,7 +560,7 @@ let link ppf objfiles output_name =
         if not (Filename.check_suffix output_name Config.ext_obj) then begin
           temps := obj_file :: !temps;
           if not (
-            let runtime_lib = "-lcamlrun" ^ !Clflags.runtime_variant in
+            let runtime_lib = "-lcamlrun @EXTRA_RT_LIBS@" ^ !Clflags.runtime_variant in
             Ccomp.call_linker Ccomp.MainDll output_name
               ([obj_file] @ List.rev !Clflags.ccobjs @ [runtime_lib])
               Config.bytecomp_c_libraries
