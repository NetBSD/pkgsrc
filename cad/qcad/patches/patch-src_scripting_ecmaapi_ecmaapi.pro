$NetBSD: patch-src_scripting_ecmaapi_ecmaapi.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/scripting/ecmaapi/ecmaapi.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/scripting/ecmaapi/ecmaapi.pro
@@ -2,6 +2,7 @@ include( ../../../shared.pri )
 TEMPLATE = lib
 CONFIG += plugin
 TARGET = $${RLIBNAME}ecmaapi
+INSTALLS += target
 CONFIG -= warn_on
 CONFIG += warn_off
 CONFIG += precompile_header
@@ -19,13 +20,13 @@ SOURCES += \
 include(adapters/adapters.pri)
 include(generated/generated.pri)
 LIBS += \
-    -l$${RLIBNAME}core \
-    -l$${RLIBNAME}entity \
-    -l$${RLIBNAME}grid \
-    -l$${RLIBNAME}gui \
-    -l$${RLIBNAME}operations \
-    -l$${RLIBNAME}snap \
-    -l$${RLIBNAME}spatialindex \
-    -l$${RLIBNAME}stemmer \
-    -l$${RLIBNAME}zip \
-    -lquazip
+    -L../../core -l$${RLIBNAME}core \
+    -L../../entity -l$${RLIBNAME}entity \
+    -L../../grid -l$${RLIBNAME}grid \
+    -L../../gui -l$${RLIBNAME}gui \
+    -L../../operations -l$${RLIBNAME}operations \
+    -L../../snap -l$${RLIBNAME}snap \
+    -L../../spatialindex -l$${RLIBNAME}spatialindex \
+    -L../../stemmer -l$${RLIBNAME}stemmer \
+    -L../../zip -l$${RLIBNAME}zip \
+    -L../../3rdparty/quazip -lquazip
