$NetBSD: patch-configure.ml,v 1.2 2016/12/30 13:23:06 jaapb Exp $

NetBSD uses md5sum too
--- configure.ml.orig	2016-10-25 20:17:16.000000000 +0000
+++ configure.ml
@@ -827,7 +827,7 @@ let strip =
 (** * md5sum command *)
 
 let md5sum =
-  if List.mem arch ["Darwin"; "FreeBSD"; "OpenBSD"]
+  if List.mem arch ["Darwin"; "FreeBSD"; "OpenBSD"; "NetBSD"]
   then "md5 -q" else "md5sum"
 
 
