$NetBSD: patch-src_system_system__generic.ml,v 1.1 2018/04/30 10:14:29 wiz Exp $

Adapt for API change.

--- src/system/system_generic.ml.orig	2018-01-27 21:12:13.000000000 +0000
+++ src/system/system_generic.ml
@@ -58,7 +58,7 @@ let readdir = Unix.readdir
 let closedir = Unix.closedir
 let readlink = Unix.readlink
 (* BCP 5/16: Eta-expand for backward compatibility with OCaml <=4.02 *)
-let symlink s1 s2 = Unix.symlink s1 s2
+let symlink ?to_dir s1 s2 = Unix.symlink ?to_dir s1 s2
 let chdir = Sys.chdir
 let getcwd = Sys.getcwd
 
