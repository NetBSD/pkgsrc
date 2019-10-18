$NetBSD: patch-system_system__generic.ml,v 1.2 2019/10/18 09:59:26 pho Exp $

Needed for compatibility with OCaml 4.08

--- system/system_generic.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ system/system_generic.ml
@@ -47,7 +47,7 @@ let open_out_gen = open_out_gen
 let chmod = Unix.chmod
 let chown = Unix.chown
 let utimes = Unix.utimes
-let link = Unix.link
+let link s d = Unix.link s d
 let openfile = Unix.openfile
 let opendir f =
   let h = Unix.opendir f in
@@ -57,7 +57,7 @@ let opendir f =
 let readdir = Unix.readdir
 let closedir = Unix.closedir
 let readlink = Unix.readlink
-let symlink = Unix.symlink
+let symlink s1 s2 = Unix.symlink s1 s2
 let chdir = Sys.chdir
 let getcwd = Sys.getcwd
 
