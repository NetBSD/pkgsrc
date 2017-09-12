$NetBSD: patch-script.ml,v 1.1 2017/09/12 06:55:42 dholland Exp $

Fix build with ocaml 4.05.

--- script.ml~	2014-02-02 12:03:02.000000000 +0000
+++ script.ml
@@ -66,7 +66,8 @@ let get_keystrings_via_http addr hashes 
   let s = Unix.socket
             ~domain:(Unix.domain_of_sockaddr addr)
             ~kind:Unix.SOCK_STREAM
-            ~protocol:0  in
+            ~protocol:0
+            ~cloexec:false in
   let () = Unix.connect s ~addr in
   let cin = Channel.sys_in_from_fd s
   and cout = Channel.sys_out_from_fd s in
@@ -94,7 +95,8 @@ let test addr hashes =
   let s = Unix.socket
             ~domain:(Unix.domain_of_sockaddr addr)
             ~kind:Unix.SOCK_STREAM
-            ~protocol:0  in
+            ~protocol:0
+            ~cloexec:false in
   let () = Unix.connect s ~addr in
   let cin = Channel.sys_in_from_fd s
   and cout = Channel.sys_out_from_fd s in
