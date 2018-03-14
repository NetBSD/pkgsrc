$NetBSD: patch-lwt_lwt__unix.mli,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- lwt/lwt_unix.mli~	2009-05-02 02:31:27.000000000 +0000
+++ lwt/lwt_unix.mli
@@ -30,8 +30,8 @@ val run : 'a Lwt.t -> 'a
    this library, you must first turn them into non-blocking mode
    using [Unix.set_nonblock]. *)
 
-val read : Unix.file_descr -> string -> int -> int -> int Lwt.t
-val write : Unix.file_descr -> string -> int -> int -> int Lwt.t
+val read : Unix.file_descr -> bytes -> int -> int -> int Lwt.t
+val write : Unix.file_descr -> bytes -> int -> int -> int Lwt.t
 val pipe : unit -> (Unix.file_descr * Unix.file_descr) Lwt.t
 val socket :
   Unix.socket_domain -> Unix.socket_type -> int -> Unix.file_descr Lwt.t
@@ -51,8 +51,8 @@ type lwt_out_channel
 
 val input_char : lwt_in_channel -> char Lwt.t
 val input_line : lwt_in_channel -> string Lwt.t
-val input : lwt_in_channel -> string -> int -> int -> int Lwt.t
-val really_input : lwt_in_channel -> string -> int -> int -> unit Lwt.t
+val input : lwt_in_channel -> bytes -> int -> int -> int Lwt.t
+val really_input : lwt_in_channel -> bytes -> int -> int -> unit Lwt.t
 
 val open_process_in: string -> lwt_in_channel Lwt.t
 val open_process_out: string -> lwt_out_channel Lwt.t
