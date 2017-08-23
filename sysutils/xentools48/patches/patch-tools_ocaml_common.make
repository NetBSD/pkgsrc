$NetBSD: patch-tools_ocaml_common.make,v 1.3 2017/08/23 03:02:14 maya Exp $

Handle ocaml-findlib 1.7.3 already appending destdir

--- tools/ocaml/common.make.orig	2016-12-05 12:03:27.000000000 +0000
+++ tools/ocaml/common.make	2017-08-18 16:00:39.195689939 +0100
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
