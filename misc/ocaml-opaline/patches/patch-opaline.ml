$NetBSD: patch-opaline.ml,v 1.1 2025/02/24 03:10:30 dholland Exp $

- Use Filename.quote when passing filenames to Sys.command, which is
like system(3). Otherwise shell metacharacters like '*' get
interpreted and things go downhill. Note that you can't quote the
install command as in general it includes arguments.

- Add support for the lib_root section.

--- opaline.ml.orig	2020-12-09 09:19:33.000000000 +0000
+++ opaline.ml
@@ -73,11 +73,11 @@ let install_file ?(exec=false) ?(man=fal
   in
   if check_file_exists ~optional src then begin
 	if !verbose then Format.printf "- installing from %s to %s@." src path;
-  ignore (Sys.command (Printf.sprintf "mkdir -p %s" (Filename.dirname path)));
+  ignore (Sys.command (Printf.sprintf "mkdir -p %s" (Filename.quote (Filename.dirname path))));
   let ret = if exec then
-   	 Sys.command (Printf.sprintf "%s %s %s" !exec_install_cmd src path)
+   	 Sys.command (Printf.sprintf "%s %s %s" !exec_install_cmd (Filename.quote src) (Filename.quote path))
   else
-   	 Sys.command (Printf.sprintf "%s %s %s" !install_cmd src path) in
+   	 Sys.command (Printf.sprintf "%s %s %s" !install_cmd (Filename.quote src) (Filename.quote path)) in
 	if ret = 0 then
 		()
 	else
@@ -104,6 +104,8 @@ let get_libdir { name ; libdir } =
 let do_install p ~section ~src ?dst () =
   if section = "lib" then
     install_file (get_libdir p) src dst
+  else if section = "lib_root" then
+    install_file p.libdir src dst
   else if section = "libexec" then
     install_file ~exec:true (get_libdir p) src dst
   else if section = "bin" then
