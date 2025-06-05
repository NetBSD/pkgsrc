$NetBSD: patch-doc_interpreter_module.mk,v 1.2 2025/06/05 10:59:35 adam Exp $

Use QHELPGENERATOR instead of QCOLLECTIONGENERATOR.

--- doc/interpreter/module.mk.orig	2025-05-29 12:16:39.000000000 +0000
+++ doc/interpreter/module.mk
@@ -269,7 +269,7 @@ if AMCOND_BUILD_QT_DOCS
 	cp -r %reldir%/octave.html %reldir%/octave.qdoc.html && \
 	$(PERL) $(srcdir)/build-aux/inplace-edit.pl 's|<a[^>]+class=.copiable[^>]+> &para;</a>||g' %reldir%/octave.qdoc.html/* && \
 	$(PERL) $(srcdir)/%reldir%/mk-qthelp.pl octave.qdoc.html %reldir%/octave_interpreter && \
-	$(QCOLLECTIONGENERATOR) $(QCOLLECTIONGENERATORFLAGS) %reldir%/octave_interpreter.qhcp -o %reldir%/octave_interpreter.qhc >/dev/null && \
+	$(QHELPGENERATOR) $(QHELPGENERATORFLAGS) %reldir%/octave_interpreter.qhcp -o %reldir%/octave_interpreter.qhc >/dev/null && \
 	rm -f %reldir%/octave_interpreter.qhcp %reldir%/octave_interpreter.qhp && \
 	rm -rf %reldir%/octave.qdoc.html
 
