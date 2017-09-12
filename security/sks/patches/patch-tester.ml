$NetBSD: patch-tester.ml,v 1.1 2017/09/12 06:55:42 dholland Exp $

Fix build with ocaml 4.05.

--- tester.ml~	2014-02-02 12:03:02.000000000 +0000
+++ tester.ml
@@ -49,7 +49,8 @@ let send_msg addr msg =
   let s = Unix.socket
             ~domain:(Unix.domain_of_sockaddr addr)
             ~kind:Unix.SOCK_STREAM
-            ~protocol:0 in
+            ~protocol:0
+            ~cloexec:false in
   protect ~f:( fun () ->
                  Unix.connect s ~addr:addr;
                  let cin = Channel.sys_in_from_fd s
@@ -66,7 +66,8 @@ let send_msg_noreply addr msg =
   let s = Unix.socket
             ~domain:(Unix.domain_of_sockaddr addr)
             ~kind:Unix.SOCK_STREAM
-            ~protocol:0 in
+            ~protocol:0
+            ~cloexec:false in
   protect ~f:(fun () ->
                 Unix.connect s ~addr:addr;
                 let cout = Channel.sys_out_from_fd s in
