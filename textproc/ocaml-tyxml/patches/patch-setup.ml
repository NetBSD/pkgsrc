$NetBSD: patch-setup.ml,v 1.1 2017/02/15 23:19:30 joerg Exp $

--- setup.ml.orig	2017-02-15 01:14:48.393874595 +0000
+++ setup.ml
@@ -6068,12 +6068,6 @@ module InternalInstallPlugin = struct
         in
         fun () -> dn
       in
-      let () =
-        if not (OASISFileUtil.file_exists_case (findlib_dir ())) then
-          failwithf
-            (f_ "Directory '%s' doesn't exist for findlib library %s")
-            (findlib_dir ()) findlib_name
-      in
       let f dir file =
         let basename = Filename.basename file in
         let tgt_fn = Filename.concat dir basename in
