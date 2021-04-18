$NetBSD: patch-tools_ocaml_common.make,v 1.1 2021/04/18 12:31:26 bouyer Exp $

Handle ocaml-findlib 1.7.3 already appending destdir

--- tools/ocaml/common.make.orig	2020-12-08 15:28:31.000000000 +0100
+++ tools/ocaml/common.make	2021-01-09 19:27:02.447285099 +0100
@@ -3,7 +3,7 @@
 CC ?= gcc
 OCAMLOPT ?= ocamlopt
 OCAMLC ?= ocamlc
-OCAMLMKLIB ?= ocamlmklib
+OCAMLMKLIB ?= ocamlmklib -elfmode
 OCAMLDEP ?= ocamldep
 OCAMLLEX ?= ocamllex
 OCAMLYACC ?= ocamlyacc
@@ -17,6 +17,6 @@
 
 VERSION := 4.1
 
-OCAMLDESTDIR ?= $(DESTDIR)$(shell $(OCAMLFIND) printconf destdir)
+OCAMLDESTDIR ?= $(shell $(OCAMLFIND) printconf destdir)
 
 o= >$@.new && mv -f $@.new $@
