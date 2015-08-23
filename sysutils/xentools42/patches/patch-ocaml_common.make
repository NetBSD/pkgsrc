$NetBSD: patch-ocaml_common.make,v 1.2 2015/08/23 16:17:12 spz Exp $

--- ocaml/common.make.orig	2014-09-02 06:22:57.000000000 +0000
+++ ocaml/common.make
@@ -3,7 +3,7 @@ include $(XEN_ROOT)/tools/Rules.mk
 CC ?= gcc
 OCAMLOPT ?= ocamlopt
 OCAMLC ?= ocamlc
-OCAMLMKLIB ?= ocamlmklib
+OCAMLMKLIB ?= ocamlmklib -elfmode
 OCAMLDEP ?= ocamldep
 OCAMLLEX ?= ocamllex
 OCAMLYACC ?= ocamlyacc
