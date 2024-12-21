$NetBSD: patch-tools_ocaml_common.make,v 1.2 2024/12/21 16:01:48 bouyer Exp $

Handle ocaml-findlib 1.7.3 already appending destdir

--- tools/ocaml/common.make.orig	2024-12-19 09:04:30.000000000 +0100
+++ tools/ocaml/common.make	2024-12-21 13:28:30.660273010 +0100
@@ -3,7 +3,7 @@
 CC ?= gcc
 OCAMLOPT ?= ocamlopt
 OCAMLC ?= ocamlc
-OCAMLMKLIB ?= ocamlmklib
+OCAMLMKLIB ?= ocamlmklib -elfmode
 OCAMLDEP ?= ocamldep
 OCAMLLEX ?= ocamllex
 OCAMLYACC ?= ocamlyacc
@@ -16,6 +16,6 @@
 
 VERSION := $(shell $(XEN_ROOT)/version.sh $(XEN_ROOT)/xen/Makefile)
 
-OCAMLDESTDIR ?= $(DESTDIR)$(shell $(OCAMLFIND) printconf destdir)
+OCAMLDESTDIR ?= $(shell $(OCAMLFIND) printconf destdir)
 
 o= >$@.new && mv -f $@.new $@
