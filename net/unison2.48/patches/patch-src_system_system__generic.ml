$NetBSD: patch-src_system_system__generic.ml,v 1.1 2019/07/29 18:07:10 wiz Exp $

Needed for compatibility with OCaml 4.08
--- src/system/system_generic.ml.orig	2017-12-18 12:23:54.000000000 +0000
+++ src/system/system_generic.ml
@@ -47,7 +47,7 @@ let open_out_gen = open_out_gen
 let chmod = Unix.chmod
 let chown = Unix.chown
 let utimes = Unix.utimes
-let link = Unix.link
+let link s d = Unix.link s d
 let openfile = Unix.openfile
 let opendir f =
   let h = Unix.opendir f in
