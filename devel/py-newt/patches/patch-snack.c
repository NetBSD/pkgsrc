$NetBSD: patch-snack.c,v 1.1 2025/05/06 20:35:02 vins Exp $

* newtInit() should only be called once.
* PyObject_NEW does not check \var{type} for a NULL value

--- snack.c.orig	2025-03-10 13:29:06.000000000 +0000
+++ snack.c
@@ -366,7 +366,7 @@ static PyTypeObject snackWidgetType = {
 static snackWidget * snackWidgetNew (void) {
     snackWidget * widget;
      
-    widget = PyObject_NEW(snackWidget, &snackWidgetType);
+    widget = PyObject_New(snackWidget, &snackWidgetType);
     if (!widget)
 	return NULL;
 
@@ -932,7 +932,7 @@ static snackForm * formCreate(PyObject *
     if (help == Py_None)
 	help = NULL;
 
-    form = PyObject_NEW(snackForm, &snackFormType);
+    form = PyObject_New(snackForm, &snackFormType);
     form->fo = newtForm(NULL, help, 0);
 
     return form;
@@ -944,7 +944,7 @@ static snackGrid * gridCreate(PyObject *
 
     if (!PyArg_ParseTuple(args, "ii", &cols, &rows)) return NULL;
 
-    grid = PyObject_NEW(snackGrid, &snackGridType);
+    grid = PyObject_New(snackGrid, &snackGridType);
     grid->grid = newtCreateGrid(cols, rows);
 
     return grid;
