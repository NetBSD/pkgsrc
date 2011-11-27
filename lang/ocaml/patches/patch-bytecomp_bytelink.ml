$NetBSD: patch-bytecomp_bytelink.ml,v 1.1 2011/11/27 19:46:00 joerg Exp $

--- bytecomp/bytelink.ml.orig	2011-11-26 23:11:19.000000000 +0000
+++ bytecomp/bytelink.ml
@@ -467,7 +467,7 @@ void caml_startup(char ** argv)\n\
 
 let build_custom_runtime prim_name exec_name =
   Ccomp.call_linker Ccomp.Exe exec_name
-    ([prim_name] @ List.rev !Clflags.ccobjs @ ["-lcamlrun"])
+    ([prim_name] @ List.rev !Clflags.ccobjs @ ["-lcamlrun @EXTRA_RT_LIBS@"])
     (Clflags.std_include_flag "-I" ^ " " ^ Config.bytecomp_c_libraries)
 
 let append_bytecode_and_cleanup bytecode_name exec_name prim_name =
@@ -547,7 +547,7 @@ let link objfiles output_name =
           temps := obj_file :: !temps;
           if not (
             Ccomp.call_linker Ccomp.MainDll output_name
-              ([obj_file] @ List.rev !Clflags.ccobjs @ ["-lcamlrun"])
+              ([obj_file] @ List.rev !Clflags.ccobjs @ ["-lcamlrun @EXTRA_RT_LIBS@"])
               Config.bytecomp_c_libraries
            ) then raise (Error Custom_runtime);
         end
