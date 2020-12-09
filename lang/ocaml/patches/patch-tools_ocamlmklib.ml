$NetBSD: patch-tools_ocamlmklib.ml,v 1.1 2020/12/09 10:33:04 jaapb Exp $

Add ELF mode support to ocamlmklib

--- tools/ocamlmklib.ml.orig	2019-02-08 14:34:11.000000000 +0000
+++ tools/ocamlmklib.ml
@@ -43,6 +43,7 @@ and c_objs = ref []         (* .o, .a, .
 and caml_libs = ref []      (* -cclib to pass to ocamlc, ocamlopt *)
 and caml_opts = ref []      (* -ccopt to pass to ocamlc, ocamlopt *)
 and dynlink = ref supports_shared_libraries
+and elfmode = ref false     (* do not add C link lib path to run-time path *)
 and failsafe = ref false    (* whether to fall back on static build only *)
 and c_libs = ref []         (* libs to pass to mksharedlib and ocamlc -cclib *)
 and c_Lopts = ref []      (* options to pass to mksharedlib and ocamlc -cclib *)
@@ -110,6 +111,8 @@ let parse_arguments argv =
       c_objs := s :: !c_objs
     else if s = "-cclib" then
       caml_libs := next_arg s :: "-cclib" :: !caml_libs
+		else if starts_with s "-Wl,-z" then
+			c_libs := s :: !c_libs
     else if s = "-ccopt" then
       caml_opts := next_arg s :: "-ccopt" :: !caml_opts
     else if s = "-custom" then
@@ -136,8 +139,9 @@ let parse_arguments argv =
       c_libs := s :: !c_libs
     else if starts_with s "-L" then
      (c_Lopts := s :: !c_Lopts;
-      let l = chop_prefix s "-L" in
-      if not (Filename.is_relative l) then rpath := l :: !rpath)
+		 if not !elfmode then
+     (let l = chop_prefix s "-L" in
+      if not (Filename.is_relative l) then rpath := l :: !rpath))
     else if s = "-ocamlcflags" then
       ocamlc_opts := next_arg s :: !ocamlc_opts
     else if s = "-ocamlc" then
@@ -152,6 +156,8 @@ let parse_arguments argv =
       output_c := next_arg s
     else if s = "-dllpath" || s = "-R" || s = "-rpath" then
       rpath := next_arg s :: !rpath
+		else if s = "-elfmode" then
+		  elfmode := true
     else if starts_with s "-R" then
       rpath := chop_prefix s "-R" :: !rpath
     else if s = "-Wl,-rpath" then
@@ -200,6 +206,7 @@ Usage: ocamlmklib [options] <.cmo|.cma|.
 \n  -custom        Disable dynamic loading\
 \n  -g             Build with debug information\
 \n  -dllpath <dir> Add <dir> to the run-time search path for DLLs\
+\n  -elfmode       Do not add link-time search path to run-time path\
 \n  -F<dir>        Specify a framework directory (MacOSX)\
 \n  -framework <name>    Use framework <name> (MacOSX)\
 \n  -help          Print this help message and exit\
