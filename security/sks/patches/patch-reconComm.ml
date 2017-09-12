$NetBSD: patch-reconComm.ml,v 1.1 2017/09/12 06:55:42 dholland Exp $

Fix build with ocaml 4.05.

--- reconComm.ml~	2014-02-02 12:03:02.000000000 +0000
+++ reconComm.ml
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
@@ -57,7 +58,8 @@ let send_dbmsg_noreply msg =
   let s = Unix.socket
             ~domain:(Unix.domain_of_sockaddr db_command_addr)
             ~kind:Unix.SOCK_STREAM
-            ~protocol:0 in
+            ~protocol:0
+            ~cloexec:false in
   protect ~f:(fun () ->
                 Unix.connect s ~addr:db_command_addr;
                 let cout = Channel.sys_out_from_fd s in
@@ -78,7 +80,8 @@ let get_keystrings_via_http addr hashes 
   let s = Unix.socket
             ~domain:(Unix.domain_of_sockaddr addr)
             ~kind:Unix.SOCK_STREAM
-            ~protocol:0  in
+            ~protocol:0
+            ~cloexec:false in
   protect ~f:(fun () ->
                 Unix.bind s ~addr:(match_client_recon_addr addr);
                 Unix.connect s ~addr;
