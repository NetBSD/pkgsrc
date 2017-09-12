$NetBSD: patch-eventloop.ml,v 1.1 2017/09/12 06:55:42 dholland Exp $

Fix build with ocaml 4.05.

--- eventloop.ml~	2014-02-02 12:03:02.000000000 +0000
+++ eventloop.ml
@@ -129,7 +129,7 @@ let create_sock addr =
     let domain =
       Unix.domain_of_sockaddr addr in
     let sock =
-      socket ~domain ~kind:SOCK_STREAM ~protocol:0 in
+      socket ~domain ~kind:SOCK_STREAM ~protocol:0 ~cloexec:false in
     setsockopt sock SO_REUSEADDR true;
     if domain = PF_INET6 then
       setsockopt sock IPV6_ONLY true;
