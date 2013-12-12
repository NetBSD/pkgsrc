$NetBSD: patch-src_src.pro,v 1.1 2013/12/12 10:03:42 markd Exp $

Always install into $PREFIX/lib not $PREFIX/lib64

--- src/src.pro.orig	2010-08-01 14:08:59.000000000 +0000
+++ src/src.pro
@@ -61,11 +61,11 @@ else:unix {
     system( ./pcfile.sh $${INSTALL_PREFIX} $${VERSION} )
     pkgconfig.files = qoauth.pc
     
-    contains(QMAKE_HOST.arch, x86_64) {
-      target.path = $${INSTALL_PREFIX}/lib64
-    } else {
+    #contains(QMAKE_HOST.arch, x86_64) {
+    #  target.path = $${INSTALL_PREFIX}/lib64
+    #} else {
       target.path = $${INSTALL_PREFIX}/lib
-    }
+    #}
 
     headers.path = $${INSTALL_PREFIX}/include/QtOAuth
     docs.path = $${INSTALL_PREFIX}/share/doc/$${TARGET}-$${VERSION}/html
