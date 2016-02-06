$NetBSD: patch-configure.ml,v 1.1 2016/02/06 16:08:36 jaapb Exp $

NetBSD uses md5sum too
--- configure.ml.orig	2015-12-16 23:44:44.000000000 +0000
+++ configure.ml
@@ -843,7 +843,7 @@ let strip =
 (** * md5sum command *)
 
 let md5sum =
-  if arch = "Darwin" then "md5 -q" else "md5sum"
+  if arch = "Darwin" || arch = "NetBSD" then "md5 -q" else "md5sum"
 
 
 (** * Documentation : do we have latex, hevea, ... *)
