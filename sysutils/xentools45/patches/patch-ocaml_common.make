$NetBSD: patch-ocaml_common.make,v 1.3 2018/01/27 19:11:41 abs Exp $

Handle ocaml-findlib 1.7.3 already appending DESTDIR
Add -unsafe-string to fix build with ocaml-4.06.0 and later. ++PKGREVISION

--- ocaml/common.make.orig	2016-09-20 05:59:24.000000000 +0000
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
@@ -12,11 +12,11 @@ OCAMLFIND ?= ocamlfind
 CFLAGS += -fPIC -Werror -I$(shell ocamlc -where)
 
 OCAMLOPTFLAG_G := $(shell $(OCAMLOPT) -h 2>&1 | sed -n 's/^  *\(-g\) .*/\1/p')
-OCAMLOPTFLAGS = $(OCAMLOPTFLAG_G) -ccopt "$(LDFLAGS)" -dtypes $(OCAMLINCLUDE) -cc $(CC) -w F -warn-error F
-OCAMLCFLAGS += -g $(OCAMLINCLUDE) -w F -warn-error F
+OCAMLOPTFLAGS = $(OCAMLOPTFLAG_G) -unsafe-string -ccopt "$(LDFLAGS)" -dtypes $(OCAMLINCLUDE) -cc $(CC) -w F -warn-error F
+OCAMLCFLAGS += -unsafe-string -g $(OCAMLINCLUDE) -w F -warn-error F
 
 VERSION := 4.1
 
-OCAMLDESTDIR ?= $(DESTDIR)$(shell $(OCAMLFIND) printconf destdir)
+OCAMLDESTDIR ?= $(shell $(OCAMLFIND) printconf destdir)
 
 o= >$@.new && mv -f $@.new $@
