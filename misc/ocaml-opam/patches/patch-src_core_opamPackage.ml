$NetBSD: patch-src_core_opamPackage.ml,v 1.1 2016/06/19 23:23:02 jaapb Exp $

Reflect API change in dose3
--- src/core/opamPackage.ml.orig	2015-04-27 07:46:51.000000000 +0000
+++ src/core/opamPackage.ml
@@ -29,7 +29,7 @@ module Version = struct
 
   let of_string x = x
 
-  let compare = Debian.Version.compare
+  let compare = Versioning.Debian.compare
 
   let to_json x =
     `String (to_string x)
