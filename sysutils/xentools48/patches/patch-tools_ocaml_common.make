$NetBSD: patch-tools_ocaml_common.make,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/ocaml/common.make.orig	2015-01-12 17:53:24.000000000 +0100
+++ tools/ocaml/common.make	2015-01-19 13:16:38.000000000 +0100
@@ -3,7 +3,7 @@
 CC ?= gcc
 OCAMLOPT ?= ocamlopt
 OCAMLC ?= ocamlc
-OCAMLMKLIB ?= ocamlmklib
+OCAMLMKLIB ?= ocamlmklib -elfmode
 OCAMLDEP ?= ocamldep
 OCAMLLEX ?= ocamllex
 OCAMLYACC ?= ocamlyacc
