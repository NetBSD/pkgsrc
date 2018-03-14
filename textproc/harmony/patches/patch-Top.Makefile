$NetBSD: patch-Top.Makefile,v 1.1 2018/03/14 06:27:21 dholland Exp $

Fix energizer-bunny-makefiles.
Eliminate references to included ocaml-csv; use the pkgsrc one.

--- Top.Makefile.orig	2006-05-21 17:18:37.000000000 +0000
+++ Top.Makefile
@@ -48,15 +48,15 @@ OCAMLFIND_COMMANDS=$(foreach c,ocamlc oc
 
 OCAMLMAKEFILE = $(SRCDIR)/OCamlMakefile
 
-PACKS = "netstring,unix,str,pxp,pxp-engine,pxp-lex-utf8" 
+PACKS = "netstring,unix,str,pxp,pxp-engine,pxp-lex-utf8,csv" 
 YFLAGS = -v 
 OCAMLFLAGS = -dtypes -rectypes
 OCAMLCPFLAGS = f
 
 LIBS += csv 
 
-LIBDIRS = $(SRCDIR) $(SRCDIR)/ubase $(EXTERNDIR)/ocaml-csv-1.0.3
-INCDIRS = $(SRCDIR) $(SRCDIR)/ubase $(EXTERNDIR)/ocaml-csv-1.0.3
+LIBDIRS = $(SRCDIR) $(SRCDIR)/ubase
+INCDIRS = $(SRCDIR) $(SRCDIR)/ubase
 
 
 $(SRCDIR)/harmony.cmxa: 
@@ -104,12 +104,12 @@ clean:: tidy
 	rm -rf *.aux *.bbl *.blg *.log *.dvi TAGS *.cmo *.cmi *.cmx *.o 
 	@for i in $(SUBDIRS) $(SUBDIRSCLEANONLY); do \
 	    echo "###### cleaning $(CWD)/$$i ######"; \
-	    $(MAKE) -C $$i clean; done
+	    $(MAKE) -C $$i clean || exit 1; done
 
 buildsubdirs:
 	@for i in $(SUBDIRS); do \
 	    echo "###### Building $(CWD)/$$i ######"; \
-	    $(MAKE) -C $$i; done
+	    $(MAKE) -C $$i || exit 1; done
 
 
 tidy::
@@ -154,5 +154,5 @@ buildtags:
 
 # Benjamin, please include things like this in your ~/.harmony.mk file instead :-)
 #
-# export BCPDEPFLAGS = -I $(SRCDIR) -I $(SRCDIR)/ubase $(EXTERNDIR)/ocaml-csv-1.0.3
+# export BCPDEPFLAGS = -I $(SRCDIR) -I $(SRCDIR)/ubase
 #
