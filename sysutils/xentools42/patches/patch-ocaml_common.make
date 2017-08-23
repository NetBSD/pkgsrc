$NetBSD: patch-ocaml_common.make,v 1.3 2017/08/23 02:57:09 maya Exp $

Handle ocaml-findlib 1.7.3 already appending DESTDIR

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
@@ -16,6 +16,6 @@ OCAMLCFLAGS += -g $(OCAMLINCLUDE) -w F -
 
 VERSION := 4.1
 
-OCAMLDESTDIR ?= $(DESTDIR)$(shell ocamlfind printconf destdir)
+OCAMLDESTDIR ?= $(shell ocamlfind printconf destdir)
 
 o= >$@.new && mv -f $@.new $@
