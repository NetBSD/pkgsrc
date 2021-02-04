--- tools/ocaml/common.make.orig	2020-04-17 13:58:20.000000000 +0200
+++ tools/ocaml/common.make	2021-02-04 11:25:02.393221932 +0100
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
