$NetBSD: patch-Modules___cursesmodule.c,v 1.3 2017/01/05 23:16:42 roy Exp $

Allow py-curses to use NetBSD curses as well as ncurses
http://bugs.python.org/issue21457

--- Modules/_cursesmodule.c.orig	2016-06-25 21:38:38.000000000 +0000
+++ Modules/_cursesmodule.c
@@ -112,12 +112,7 @@ char *PyCursesVersion = "2.2";
 #define CURSES_MODULE
 #include "py_curses.h"
 
-/*  These prototypes are in <term.h>, but including this header
-    #defines many common symbols (such as "lines") which breaks the
-    curses module in other ways.  So the code will just specify
-    explicit prototypes here. */
-extern int setupterm(char *,int,int *);
-#ifdef __sgi
+#ifdef HAVE_TERM_H
 #include <term.h>
 #endif
 
@@ -486,17 +481,9 @@ Window_NoArg2TupleReturnFunction(getpary
 
 Window_OneArgNoReturnFunction(clearok, int, "i;True(1) or False(0)")
 Window_OneArgNoReturnFunction(idlok, int, "i;True(1) or False(0)")
-#if defined(__NetBSD__)
-Window_OneArgNoReturnVoidFunction(keypad, int, "i;True(1) or False(0)")
-#else
 Window_OneArgNoReturnFunction(keypad, int, "i;True(1) or False(0)")
-#endif
 Window_OneArgNoReturnFunction(leaveok, int, "i;True(1) or False(0)")
-#if defined(__NetBSD__)
-Window_OneArgNoReturnVoidFunction(nodelay, int, "i;True(1) or False(0)")
-#else
 Window_OneArgNoReturnFunction(nodelay, int, "i;True(1) or False(0)")
-#endif
 Window_OneArgNoReturnFunction(notimeout, int, "i;True(1) or False(0)")
 Window_OneArgNoReturnFunction(scrollok, int, "i;True(1) or False(0)")
 Window_OneArgNoReturnFunction(winsdelln, int, "i;nlines")
@@ -1070,7 +1057,7 @@ PyCursesWindow_EchoChar(PyCursesWindowOb
         return NULL;
 
 #ifdef WINDOW_HAS_FLAGS
-    if (self->win->_flags & _ISPAD)
+    if (is_pad(self->win))
         return PyCursesCheckERR(pechochar(self->win, ch | attr),
                                 "echochar");
     else
@@ -1156,11 +1143,7 @@ PyCursesWindow_GetKey(PyCursesWindowObje
         return Py_BuildValue("C", rtn);
     } else {
         const char *knp;
-#if defined(__NetBSD__)
-        knp = unctrl(rtn);
-#else
         knp = keyname(rtn);
-#endif
         return PyUnicode_FromString((knp == NULL) ? "" : knp);
     }
 }
@@ -1593,7 +1576,7 @@ PyCursesWindow_NoOutRefresh(PyCursesWind
 #ifndef WINDOW_HAS_FLAGS
     if (0)
 #else
-        if (self->win->_flags & _ISPAD)
+        if (is_pad(self->win))
 #endif
         {
             switch(PyTuple_Size(args)) {
@@ -1768,7 +1751,7 @@ PyCursesWindow_Refresh(PyCursesWindowObj
 #ifndef WINDOW_HAS_FLAGS
     if (0)
 #else
-        if (self->win->_flags & _ISPAD)
+        if (is_pad(self->win))
 #endif
         {
             switch(PyTuple_Size(args)) {
@@ -1835,7 +1818,7 @@ PyCursesWindow_SubWin(PyCursesWindowObje
 
     /* printf("Subwin: %i %i %i %i   \n", nlines, ncols, begin_y, begin_x); */
 #ifdef WINDOW_HAS_FLAGS
-    if (self->win->_flags & _ISPAD)
+    if (is_pad(self->win))
         win = subpad(self->win, nlines, ncols, begin_y, begin_x);
     else
 #endif
@@ -2576,15 +2559,15 @@ PyCurses_IntrFlush(PyObject *self, PyObj
 static PyObject *
 PyCurses_Is_Term_Resized(PyObject *self, PyObject *args)
 {
-    int lines;
-    int columns;
+    int nlines;
+    int ncolumns;
     int result;
 
     PyCursesInitialised;
 
-    if (!PyArg_ParseTuple(args,"ii:is_term_resized", &lines, &columns))
+    if (!PyArg_ParseTuple(args,"ii:is_term_resized", &nlines, &ncolumns))
         return NULL;
-    result = is_term_resized(lines, columns);
+    result = is_term_resized(nlines, ncolumns);
     if (result == TRUE) {
         Py_INCREF(Py_True);
         return Py_True;
@@ -2595,7 +2578,6 @@ PyCurses_Is_Term_Resized(PyObject *self,
 }
 #endif /* HAVE_CURSES_IS_TERM_RESIZED */
 
-#if !defined(__NetBSD__)
 static PyObject *
 PyCurses_KeyName(PyObject *self, PyObject *args)
 {
@@ -2614,7 +2596,6 @@ PyCurses_KeyName(PyObject *self, PyObjec
 
     return PyBytes_FromString((knp == NULL) ? "" : knp);
 }
-#endif
 
 static PyObject *
 PyCurses_KillChar(PyObject *self)
@@ -2879,16 +2860,16 @@ PyCurses_update_lines_cols(PyObject *sel
 static PyObject *
 PyCurses_ResizeTerm(PyObject *self, PyObject *args)
 {
-    int lines;
-    int columns;
+    int nlines;
+    int ncolumns;
     PyObject *result;
 
     PyCursesInitialised;
 
-    if (!PyArg_ParseTuple(args,"ii:resizeterm", &lines, &columns))
+    if (!PyArg_ParseTuple(args,"ii:resizeterm", &nlines, &ncolumns))
         return NULL;
 
-    result = PyCursesCheckERR(resizeterm(lines, columns), "resizeterm");
+    result = PyCursesCheckERR(resizeterm(nlines, ncolumns), "resizeterm");
     if (!result)
         return NULL;
     if (!update_lines_cols())
@@ -2902,17 +2883,17 @@ PyCurses_ResizeTerm(PyObject *self, PyOb
 static PyObject *
 PyCurses_Resize_Term(PyObject *self, PyObject *args)
 {
-    int lines;
-    int columns;
+    int nlines;
+    int ncolumns;
 
     PyObject *result;
 
     PyCursesInitialised;
 
-    if (!PyArg_ParseTuple(args,"ii:resize_term", &lines, &columns))
+    if (!PyArg_ParseTuple(args,"ii:resize_term", &nlines, &ncolumns))
         return NULL;
 
-    result = PyCursesCheckERR(resize_term(lines, columns), "resize_term");
+    result = PyCursesCheckERR(resize_term(nlines, ncolumns), "resize_term");
     if (!result)
         return NULL;
     if (!update_lines_cols())
@@ -3228,9 +3209,7 @@ static PyMethodDef PyCurses_methods[] = 
 #ifdef HAVE_CURSES_IS_TERM_RESIZED
     {"is_term_resized",     (PyCFunction)PyCurses_Is_Term_Resized, METH_VARARGS},
 #endif
-#if !defined(__NetBSD__)
     {"keyname",             (PyCFunction)PyCurses_KeyName, METH_VARARGS},
-#endif
     {"killchar",            (PyCFunction)PyCurses_KillChar, METH_NOARGS},
     {"longname",            (PyCFunction)PyCurses_longname, METH_NOARGS},
     {"meta",                (PyCFunction)PyCurses_Meta, METH_VARARGS},
@@ -3359,9 +3338,7 @@ PyInit__curses(void)
     SetDictInt("A_DIM",                 A_DIM);
     SetDictInt("A_BOLD",                A_BOLD);
     SetDictInt("A_ALTCHARSET",          A_ALTCHARSET);
-#if !defined(__NetBSD__)
     SetDictInt("A_INVIS",           A_INVIS);
-#endif
     SetDictInt("A_PROTECT",         A_PROTECT);
     SetDictInt("A_CHARTEXT",        A_CHARTEXT);
     SetDictInt("A_COLOR",           A_COLOR);
@@ -3433,7 +3410,6 @@ PyInit__curses(void)
         int key;
         char *key_n;
         char *key_n2;
-#if !defined(__NetBSD__)
         for (key=KEY_MIN;key < KEY_MAX; key++) {
             key_n = (char *)keyname(key);
             if (key_n == NULL || strcmp(key_n,"UNKNOWN KEY")==0)
@@ -3461,7 +3437,6 @@ PyInit__curses(void)
             if (key_n2 != key_n)
                 PyMem_Free(key_n2);
         }
-#endif
         SetDictInt("KEY_MIN", KEY_MIN);
         SetDictInt("KEY_MAX", KEY_MAX);
     }
