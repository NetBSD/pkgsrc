$NetBSD: patch-ocaml_common.make,v 1.2 2017/08/23 02:49:48 maya Exp $

Handle ocaml-findlib 1.7.3 already appending DESTDIR

--- ocaml/common.make.orig	2015-01-12 17:53:24.000000000 +0100
+++ ocaml/common.make	2015-01-19 13:16:38.000000000 +0100
++ work/xen-4.5.5/tools/ocaml/common.make
@@ -3,7 +3,7 @@ include $(XEN_ROOT)/tools/Rules.mk
 CC ?= gcc
 OCAMLOPT ?= ocamlopt
 OCAMLC ?= ocamlc
-OCAMLMKLIB ?= ocamlmklib
+OCAMLMKLIB ?= ocamlmklib -elfmode
 OCAMLDEP ?= ocamldep
 OCAMLLEX ?= ocamllex
 OCAMLYACC ?= ocamlyacc
@@ -17,6 +17,6 @@ OCAMLCFLAGS += -g $(OCAMLINCLUDE) -w F -
 
 VERSION := 4.1
 
-OCAMLDESTDIR ?= $(DESTDIR)$(shell $(OCAMLFIND) printconf destdir)
+OCAMLDESTDIR ?= $(shell $(OCAMLFIND) printconf destdir)
 
 o= >$@.new && mv -f $@.new $@
