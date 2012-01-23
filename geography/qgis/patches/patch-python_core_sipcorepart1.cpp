$NetBSD: patch-python_core_sipcorepart1.cpp,v 1.1 2012/01/23 08:58:00 adam Exp $

Fix C++ errors.

--- python/core/sipcorepart1.cpp.orig	2012-01-23 06:43:32.000000000 +0000
+++ python/core/sipcorepart1.cpp
@@ -6661,7 +6661,7 @@ static PyObject *meth_QgsSymbolV2_render
     PyObject *sipParseErr = NULL;
 
     {
-        const QgsSymbolV2 *sipCpp;
+        QgsSymbolV2 *sipCpp;
 
         if (sipParseArgs(&sipParseErr, sipArgs, "B", &sipSelf, sipType_QgsSymbolV2, &sipCpp))
         {
@@ -7061,7 +7061,7 @@ static PyObject *meth_QgsSymbolV2RenderC
 
     {
         bool a0;
-        const QgsSymbolV2RenderContext *sipCpp;
+        QgsSymbolV2RenderContext *sipCpp;
 
         if (sipParseArgs(&sipParseErr, sipArgs, "Bb", &sipSelf, sipType_QgsSymbolV2RenderContext, &sipCpp, &a0))
         {
