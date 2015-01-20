$NetBSD: patch-ocaml_common.make,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- ocaml/common.make.orig	2015-01-12 17:53:24.000000000 +0100
+++ ocaml/common.make	2015-01-19 13:16:38.000000000 +0100
@@ -3,7 +3,7 @@
 CC ?= gcc
 OCAMLOPT ?= ocamlopt
 OCAMLC ?= ocamlc
-OCAMLMKLIB ?= ocamlmklib
+OCAMLMKLIB ?= ocamlmklib -elfmode
 OCAMLDEP ?= ocamldep
 OCAMLLEX ?= ocamllex
 OCAMLYACC ?= ocamlyacc
