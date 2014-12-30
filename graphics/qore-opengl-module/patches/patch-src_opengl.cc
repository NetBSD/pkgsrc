$NetBSD: patch-src_opengl.cc,v 1.1 2014/12/30 15:57:10 wiz Exp $

* alloca is in stdlib.h on bsd systems 
http://sourceforge.net/p/qore/code/6300/
--- src/opengl.cc.orig	2009-09-21 11:55:18.000000000 +0000
+++ src/opengl.cc
@@ -22,7 +22,9 @@
 
 #include "qore-opengl.h"
 
+#ifdef HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 
 static QoreStringNode *opengl_module_init();
 static void opengl_module_ns_init(QoreNamespace *rns, QoreNamespace *qns);
