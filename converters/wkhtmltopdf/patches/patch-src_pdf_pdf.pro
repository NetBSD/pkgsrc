$NetBSD: patch-src_pdf_pdf.pro,v 1.3 2023/01/20 16:26:56 manu Exp $

--- src/pdf/pdf.pro.orig	2017-09-10 12:26:34.883613832 +0000
+++ src/pdf/pdf.pro
@@ -23,6 +23,8 @@ DESTDIR = ../../bin
 DEPENDPATH += . ../shared
 INCLUDEPATH += . ../shared
 
+LIBS+= ${COMPILER_RPATH_FLAG}${X11BASE}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib
+
 unix {
     man.path=$$INSTALLBASE/share/man/man1
     man.extra=LD_LIBRARY_PATH=../../bin/ ../../bin/wkhtmltopdf --manpage | gzip > $(INSTALL_ROOT)$$INSTALLBASE/share/man/man1/wkhtmltopdf.1.gz
@@ -48,4 +50,6 @@
 
 #Application part
 SOURCES += wkhtmltopdf.cc pdfarguments.cc pdfcommandlineparser.cc \
            pdfdocparts.cc
+
+LIBS += -lcrypto -lssl
