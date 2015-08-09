$NetBSD: patch-query.mli,v 1.1 2015/08/09 13:21:42 jaapb Exp $

Moved classes to separate module for ocaml 4.02.
--- query.mli.orig	2007-03-07 21:53:54.000000000 +0000
+++ query.mli
@@ -1,5 +1,5 @@
 type t
-val make : #App.t -> t
+val make : #App_types.t -> t
 
 val clear    : t -> unit
 val activate : t -> unit
