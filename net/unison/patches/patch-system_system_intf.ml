$NetBSD: patch-system_system_intf.ml,v 1.1 2016/05/06 14:29:04 jaapb Exp $

Solve compilation problem with ocaml 4.03
--- system/system_intf.ml.orig	2014-12-29 18:34:45.000000000 +0000
+++ system/system_intf.ml
@@ -20,7 +20,7 @@ module type Core = sig
 type fspath
 type dir_handle = { readdir : unit -> string; closedir : unit -> unit }
 
-val symlink : string -> fspath -> unit
+val symlink : ?to_dir:bool -> string -> fspath -> unit
 val readlink : fspath -> string
 val chown : fspath -> int -> int -> unit
 val chmod : fspath -> int -> unit
