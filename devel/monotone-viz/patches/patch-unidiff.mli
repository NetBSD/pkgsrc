$NetBSD: patch-unidiff.mli,v 1.1 2015/08/09 13:21:42 jaapb Exp $

Moved classes to separate module for ocaml 4.02.
--- unidiff.mli.orig	2007-03-07 21:53:54.000000000 +0000
+++ unidiff.mli
@@ -1 +1 @@
-val show : #App.t -> string -> string -> unit
+val show : #App_types.t -> string -> string -> unit
