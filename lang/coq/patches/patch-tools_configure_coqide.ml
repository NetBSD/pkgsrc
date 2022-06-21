$NetBSD: patch-tools_configure_coqide.ml,v 1.1 2022/06/21 02:21:22 dholland Exp $

For some reason the installed library metadata for lablgtk3 is lacking
the version number. Until this gets sorted out, accept the
[unspecified] version string that ocamlfind prints; pkgsrc does the
necessary version checks.

--- tools/configure/coqide.ml~	2022-05-31 08:36:38.000000000 +0000
+++ tools/configure/coqide.ml
@@ -25,6 +25,7 @@ let get_lablgtkdir ocamlfind =
 
 let check_lablgtk_version ocamlfind =
   let v, _ = tryrun ocamlfind ["query"; "-format"; "%v"; "lablgtk3"] in
+  if v = "[unspecified]" then (true, v) else
   try
     let vn = generic_version_nums ~name:"lablgtk3" v in
     if vn < [3; 1; 0] then
