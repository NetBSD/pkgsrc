$NetBSD: patch-system_system__generic.ml,v 1.1 2017/07/14 12:59:23 joerg Exp $

--- system/system_generic.ml.orig	2017-07-12 22:40:13.071158899 +0000
+++ system/system_generic.ml
@@ -57,7 +57,7 @@ let opendir f =
 let readdir = Unix.readdir
 let closedir = Unix.closedir
 let readlink = Unix.readlink
-let symlink = Unix.symlink
+let symlink s1 s2 = Unix.symlink s1 s2
 let chdir = Sys.chdir
 let getcwd = Sys.getcwd
 
