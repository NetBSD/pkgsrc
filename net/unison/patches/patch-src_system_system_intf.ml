$NetBSD: patch-src_system_system_intf.ml,v 1.1 2017/11/14 13:03:35 jaapb Exp $

System symlink definition has changed
--- src/system/system_intf.ml.orig	2015-10-05 18:14:23.000000000 +0000
+++ src/system/system_intf.ml
@@ -20,7 +20,7 @@ module type Core = sig
 type fspath
 type dir_handle = { readdir : unit -> string; closedir : unit -> unit }
 
-val symlink : string -> fspath -> unit
+val symlink : ?to_dir:bool -> string -> fspath -> unit
 val readlink : fspath -> string
 val chown : fspath -> int -> int -> unit
 val chmod : fspath -> int -> unit
