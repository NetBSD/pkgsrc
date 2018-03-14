$NetBSD: patch-lwt_lwt__unix.mli,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- lwt/lwt_unix.mli~	2010-04-15 17:29:31.000000000 +0000
+++ lwt/lwt_unix.mli
@@ -34,8 +34,8 @@ type file_descr
 
 val of_unix_file_descr : Unix.file_descr -> file_descr
 
-val read : file_descr -> string -> int -> int -> int Lwt.t
-val write : file_descr -> string -> int -> int -> int Lwt.t
+val read : file_descr -> bytes -> int -> int -> int Lwt.t
+val write : file_descr -> bytes -> int -> int -> int Lwt.t
 val wait_read : file_descr -> unit Lwt.t
 val wait_write : file_descr -> unit Lwt.t
 val pipe_in : unit -> file_descr * Unix.file_descr
@@ -53,4 +53,4 @@ val set_close_on_exec : file_descr -> un
 type lwt_in_channel
 
 val intern_in_channel : in_channel -> lwt_in_channel
-val input_line : lwt_in_channel -> string Lwt.t
+val input_line : lwt_in_channel -> bytes Lwt.t
