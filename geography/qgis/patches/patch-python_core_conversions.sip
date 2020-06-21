$NetBSD: patch-python_core_conversions.sip,v 1.1 2020/06/21 00:30:04 gdt Exp $

Accomodate sip 4.19.23 and qt 5.15
From
https://git.archlinux.org/svntogit/community.git/plain/trunk/qgis-pyqt-5.15.patch?h=packages/qgis&id=fef9f4c085355242e6455de901813e838cc24fd6

--- python/core/conversions.sip.orig	2019-09-13 12:11:09.000000000 +0000
+++ python/core/conversions.sip
@@ -1435,79 +1435,6 @@ template <TYPE>
 %End
 };
 
-template <TYPE>
-%MappedType QVector< TYPE* >
-{
-%TypeHeaderCode
-#include <QVector>
-%End
-
-%ConvertFromTypeCode
-    // Create the list
-    PyObject *l = PyList_New(sipCpp->size());
-
-    if (!l)
-        return NULL;
-
-    // Set the dictionary elements.
-    for( int i = 0; i < sipCpp->size(); i++ )
-    {
-        TYPE *t = sipCpp->at(i);
-        PyObject *tobj = sipConvertFromType(t, sipType_TYPE, sipTransferObj);
-
-        if (tobj == NULL || PyList_SetItem(l, i, tobj) < 0)
-        {
-            Py_DECREF(tobj);
-            Py_DECREF(l);
-            return NULL;
-        }
-    }
-
-    return l;
-%End
-
-%ConvertToTypeCode
-    // Check the type if that is all that is required.
-    if (sipIsErr == NULL)
-    {
-      if (!PyList_Check(sipPy))
-        return 0;
-
-      for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-      {
-        if (!sipCanConvertToType(PyList_GET_ITEM(sipPy, i), sipType_TYPE, SIP_NOT_NONE))
-          return 0;
-      }
-
-      return 1;
-    }
-
-    QVector<TYPE*> *v = new QVector<TYPE*>( PyList_GET_SIZE(sipPy) );
-
-    for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-    {
-      int state;
-
-      TYPE *t = reinterpret_cast<TYPE *>(sipConvertToType(PyList_GET_ITEM(sipPy, i), sipType_TYPE, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
-
-      if (*sipIsErr)
-      {
-        sipReleaseType(t, sipType_TYPE, state);
-        delete v;
-        return 0;
-      }
-
-      v->replace( i, t );
-
-      sipReleaseType(t, sipType_TYPE, state);
-    }
-
-    *sipCppPtr = v;
-
-    return sipGetState(sipTransferObj);
-%End
-};
-
 %MappedType QMap<qint64, QgsFeature*>
 {
 %TypeHeaderCode
