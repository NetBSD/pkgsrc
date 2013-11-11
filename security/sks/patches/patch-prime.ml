$NetBSD: patch-prime.ml,v 1.1 2013/11/11 15:14:13 is Exp $

--- prime.ml.orig	2012-10-07 19:59:39.000000000 +0000
+++ prime.ml
@@ -87,7 +87,7 @@ let miller_rabin rfunc n t =
   let test () =
     let a = randrange rfunc two (n -! one) in
     let y = Number.powmod a r n in
-    if y =! one or y =! neg_one then Prime
+    if y =! one || y =! neg_one then Prime
     else
       let rec loop y j =
         if y =! neg_one then Prime
