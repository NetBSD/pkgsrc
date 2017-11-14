$NetBSD: patch-src_fs.ml,v 1.1 2017/11/14 13:03:35 jaapb Exp $

System symlink definition has changed
--- src/fs.ml.orig	2015-10-05 18:14:23.000000000 +0000
+++ src/fs.ml
@@ -21,7 +21,7 @@ type fspath = Fspath.t
 type dir_handle = System.dir_handle
                 = { readdir : unit -> string; closedir : unit -> unit }
 
-let symlink l f = System.symlink l (Fspath.toString f)
+let symlink ?to_dir l f = System.symlink l (Fspath.toString f)
 
 let readlink f = System.readlink (Fspath.toString f)
 
