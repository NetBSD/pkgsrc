$NetBSD: patch-src_scripting_ecmaapi_ecmaapi.pro,v 1.2 2019/07/31 19:30:21 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/scripting/ecmaapi/ecmaapi.pro.orig	2019-02-27 15:06:55.000000000 +0000
+++ src/scripting/ecmaapi/ecmaapi.pro
@@ -2,6 +2,7 @@ include( ../../../shared.pri )
 TEMPLATE = lib
 CONFIG += plugin
 TARGET = $${RLIBNAME}ecmaapi
+INSTALLS += target
 CONFIG -= warn_on
 CONFIG += warn_off
 CONFIG += precompile_header
@@ -20,11 +21,11 @@ SOURCES += \
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
-    -l$${RLIBNAME}stemmer
+    -L../../core -l$${RLIBNAME}core \
+    -L../../entity -l$${RLIBNAME}entity \
+    -L../../grid -l$${RLIBNAME}grid \
+    -L../../gui -l$${RLIBNAME}gui \
+    -L../../operations -l$${RLIBNAME}operations \
+    -L../../snap -l$${RLIBNAME}snap \
+    -L../../spatialindex -l$${RLIBNAME}spatialindex \
+    -L../../stemmer -l$${RLIBNAME}stemmer
