$NetBSD: patch-tools_ocaml_common.make,v 1.1 2025/08/22 09:00:13 bouyer Exp $

Handle ocaml-findlib 1.7.3 already appending destdir

--- tools/ocaml/common.make.orig	2025-08-04 15:22:34.000000000 +0200
+++ tools/ocaml/common.make	2025-08-21 16:27:13.873418217 +0200
@@ -3,7 +3,7 @@
 CC ?= gcc
 OCAMLOPT ?= ocamlopt
 OCAMLC ?= ocamlc
-OCAMLMKLIB ?= ocamlmklib
+OCAMLMKLIB ?= ocamlmklib -elfmode
 OCAMLDEP ?= ocamldep
 OCAMLLEX ?= ocamllex
 OCAMLYACC ?= ocamlyacc
@@ -16,4 +16,4 @@
 
 VERSION := $(shell $(XEN_ROOT)/version.sh $(XEN_ROOT)/xen/Makefile)
 
-OCAMLDESTDIR ?= $(DESTDIR)$(shell $(OCAMLFIND) printconf destdir)
+OCAMLDESTDIR ?= $(shell $(OCAMLFIND) printconf destdir)
