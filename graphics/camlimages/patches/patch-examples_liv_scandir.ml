$NetBSD: patch-examples_liv_scandir.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Sort.list is so old it's not even in the deprecations section of the
manual any more. Use List.sort.

--- examples/liv/scandir.ml~	2011-06-22 18:04:32.000000000 +0000
+++ examples/liv/scandir.ml
@@ -31,7 +31,7 @@ let scan_dir f fn =
         | e -> prerr_endline ("readdir: " ^ Printexc.to_string e)
       end;
       closedir dh;
-      let files = Sort.list (>) !files in
+      let files = List.sort (fun x y -> -compare x y) !files in
       let subdirs = ref [] in
       let treat fn' =
         if not (fn' = ".." || fn' = ".") then begin
