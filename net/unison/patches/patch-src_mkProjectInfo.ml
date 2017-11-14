$NetBSD: patch-src_mkProjectInfo.ml,v 1.1 2017/11/14 13:03:35 jaapb Exp $

Add revision string for correct version detection
--- src/mkProjectInfo.ml.orig	2015-10-05 18:14:23.000000000 +0000
+++ src/mkProjectInfo.ml
@@ -42,7 +42,7 @@ let pointVersionOrigin = 533 (* Revision
 (* ---------------------------------------------------------------------- *)
 (* You shouldn't need to edit below. *)
 
-let revisionString = "$Rev$";;
+let revisionString = "$Rev: 548$";;
 
 let pointVersion = 
   Scanf.sscanf revisionString "$Rev: %d " (fun x -> x) - pointVersionOrigin;;
