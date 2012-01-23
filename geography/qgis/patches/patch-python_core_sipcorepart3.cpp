$NetBSD: patch-python_core_sipcorepart3.cpp,v 1.1 2012/01/23 08:58:00 adam Exp $

Fix C++ errors.

--- python/core/sipcorepart3.cpp.orig	2012-01-23 06:46:18.000000000 +0000
+++ python/core/sipcorepart3.cpp
@@ -2968,7 +2968,7 @@ static PyObject *meth_QgsMapLayer_writeX
     {
         QDomNode * a0;
         QDomDocument * a1;
-        const QgsMapLayer *sipCpp;
+        QgsMapLayer *sipCpp;
 
         if (sipParseArgs(&sipParseErr, sipArgs, "BJ9J9", &sipSelf, sipType_QgsMapLayer, &sipCpp, sipType_QDomNode, &a0, sipType_QDomDocument, &a1))
         {
