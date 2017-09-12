$NetBSD: patch-sks__do.ml,v 1.1 2017/09/12 06:55:42 dholland Exp $

Fix build with ocaml 4.05.

--- sks_do.ml~	2014-02-02 12:03:02.000000000 +0000
+++ sks_do.ml
@@ -40,7 +40,8 @@ let send_dbmsg msg =
   let s = Unix.socket
             ~domain:(Unix.domain_of_sockaddr db_command_addr)
             ~kind:Unix.SOCK_STREAM
-            ~protocol:0 in
+            ~protocol:0
+            ~cloexec:false in
   protect ~f:(fun () ->
                 Unix.connect s ~addr:db_command_addr;
                 let cin = Channel.sys_in_from_fd s in
