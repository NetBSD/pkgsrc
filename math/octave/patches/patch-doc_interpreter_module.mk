$NetBSD: patch-doc_interpreter_module.mk,v 1.1 2018/12/26 10:45:46 adam Exp $

Use QHELPGENERATOR instead of QCOLLECTIONGENERATOR.

--- doc/interpreter/module.mk.orig	2018-12-25 23:35:44.000000000 +0000
+++ doc/interpreter/module.mk
@@ -252,7 +252,7 @@ if AMCOND_BUILD_QT_DOCS
 %.qhc %.qch : $(OCTAVE_HTML_STAMP) $(HTMLDIR_CSS) %reldir%/mk-qthelp.pl
 	$(AM_V_GEN)rm -f $(OCTAVE_QTHELP_FILES) && \
 	$(PERL) $(srcdir)/%reldir%/mk-qthelp.pl octave.html %reldir%/octave_interpreter && \
-	$(QCOLLECTIONGENERATOR) $(QCOLLECTIONGENERATORFLAGS) %reldir%/octave_interpreter.qhcp -o %reldir%/octave_interpreter.qhc >/dev/null && \
+	$(QHELPGENERATOR) $(QHELPGENERATORFLAGS) %reldir%/octave_interpreter.qhcp -o %reldir%/octave_interpreter.qhc >/dev/null && \
 	rm -f %reldir%/octave_interpreter.qhcp %reldir%/octave_interpreter.qhp
 
 endif
