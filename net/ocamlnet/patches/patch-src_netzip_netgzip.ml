$NetBSD: patch-src_netzip_netgzip.ml,v 1.1 2012/08/20 08:11:58 wiz Exp $

Syntax change to conform to ocaml 4.00
--- src/netzip/netgzip.ml.orig	2012-07-19 23:25:26.000000000 +0000
+++ src/netzip/netgzip.ml
@@ -322,8 +322,8 @@ class output_deflate ?level ch =
 let () =
   Netcompression.register
     ~iana_name:"gzip"
-    ~decoder:(new inflating_pipe)
-    ~encoder:(new deflating_pipe)
+    ~decoder:(fun () -> new inflating_pipe ())
+    ~encoder:(fun () -> new deflating_pipe ())
     ()
 
 
