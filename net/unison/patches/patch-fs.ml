$NetBSD: patch-fs.ml,v 1.1 2016/05/06 14:29:04 jaapb Exp $

Solve compilation problem with ocaml 4.03
--- fs.ml.orig	2014-12-29 18:34:45.000000000 +0000
+++ fs.ml
@@ -21,7 +21,7 @@ type fspath = Fspath.t
 type dir_handle = System.dir_handle
                 = { readdir : unit -> string; closedir : unit -> unit }
 
-let symlink l f = System.symlink l (Fspath.toString f)
+let symlink ?to_dir l f = System.symlink ?to_dir l (Fspath.toString f)
 
 let readlink f = System.readlink (Fspath.toString f)
 
