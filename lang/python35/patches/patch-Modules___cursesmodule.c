$NetBSD: patch-Modules___cursesmodule.c,v 1.5 2018/06/17 19:21:22 adam Exp $

Allow py-curses to use NetBSD curses as well as ncurses
http://bugs.python.org/issue21457
Use is_pad() when supported (taken from Python 3.7).

--- Modules/_cursesmodule.c.orig	2018-02-04 23:40:56.000000000 +0000
+++ Modules/_cursesmodule.c
@@ -112,13 +112,13 @@ char *PyCursesVersion = "2.2";
 #define CURSES_MODULE
 #include "py_curses.h"
 
-/*  These prototypes are in <term.h>, but including this header
-    #defines many common symbols (such as "lines") which breaks the
-    curses module in other ways.  So the code will just specify
-    explicit prototypes here. */
-extern int setupterm(char *,int,int *);
-#ifdef __sgi
+#if defined(HAVE_TERM_H) || defined(__sgi)
+/* For termname, longname, putp, tigetflag, tigetnum, tigetstr, tparm
+   which are not declared in SysV curses and for setupterm. */
 #include <term.h>
+/* Including <term.h> #defines many common symbols. */
+#undef lines
+#undef columns
 #endif
 
 #ifdef HAVE_LANGINFO_H
@@ -494,17 +494,9 @@ Window_NoArg2TupleReturnFunction(getpary
 
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
@@ -940,6 +932,12 @@ int py_mvwdelch(WINDOW *w, int y, int x)
 }
 #endif
 
+#if defined(HAVE_CURSES_IS_PAD)
+#define py_is_pad(win)      is_pad(win)
+#elif defined(WINDOW_HAS_FLAGS)
+#define py_is_pad(win)      ((win) ? ((win)->_flags & _ISPAD) != 0 : FALSE)
+#endif
+
 /* chgat, added by Fabian Kreutz <fabian.kreutz at gmx.net> */
 
 static PyObject *
@@ -1080,7 +1078,7 @@ PyCursesWindow_EchoChar(PyCursesWindowOb
         return NULL;
 
 #ifdef WINDOW_HAS_FLAGS
-    if (self->win->_flags & _ISPAD)
+    if (py_is_pad(self->win))
         return PyCursesCheckERR(pechochar(self->win, ch | attr),
                                 "echochar");
     else
@@ -1166,11 +1164,7 @@ PyCursesWindow_GetKey(PyCursesWindowObje
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
@@ -1619,7 +1613,7 @@ PyCursesWindow_NoOutRefresh(PyCursesWind
 #ifndef WINDOW_HAS_FLAGS
     if (0)
 #else
-        if (self->win->_flags & _ISPAD)
+        if (py_is_pad(self->win))
 #endif
         {
             switch(PyTuple_Size(args)) {
@@ -1794,7 +1788,7 @@ PyCursesWindow_Refresh(PyCursesWindowObj
 #ifndef WINDOW_HAS_FLAGS
     if (0)
 #else
-        if (self->win->_flags & _ISPAD)
+        if (py_is_pad(self->win))
 #endif
         {
             switch(PyTuple_Size(args)) {
@@ -1861,7 +1855,7 @@ PyCursesWindow_SubWin(PyCursesWindowObje
 
     /* printf("Subwin: %i %i %i %i   \n", nlines, ncols, begin_y, begin_x); */
 #ifdef WINDOW_HAS_FLAGS
-    if (self->win->_flags & _ISPAD)
+    if (py_is_pad(self->win))
         win = subpad(self->win, nlines, ncols, begin_y, begin_x);
     else
 #endif
@@ -2621,7 +2615,6 @@ PyCurses_Is_Term_Resized(PyObject *self,
 }
 #endif /* HAVE_CURSES_IS_TERM_RESIZED */
 
-#if !defined(__NetBSD__)
 static PyObject *
 PyCurses_KeyName(PyObject *self, PyObject *args)
 {
@@ -2640,7 +2633,6 @@ PyCurses_KeyName(PyObject *self, PyObjec
 
     return PyBytes_FromString((knp == NULL) ? "" : knp);
 }
-#endif
 
 static PyObject *
 PyCurses_KillChar(PyObject *self)
@@ -3254,9 +3246,7 @@ static PyMethodDef PyCurses_methods[] = 
 #ifdef HAVE_CURSES_IS_TERM_RESIZED
     {"is_term_resized",     (PyCFunction)PyCurses_Is_Term_Resized, METH_VARARGS},
 #endif
-#if !defined(__NetBSD__)
     {"keyname",             (PyCFunction)PyCurses_KeyName, METH_VARARGS},
-#endif
     {"killchar",            (PyCFunction)PyCurses_KillChar, METH_NOARGS},
     {"longname",            (PyCFunction)PyCurses_longname, METH_NOARGS},
     {"meta",                (PyCFunction)PyCurses_Meta, METH_VARARGS},
@@ -3385,9 +3375,7 @@ PyInit__curses(void)
     SetDictInt("A_DIM",                 A_DIM);
     SetDictInt("A_BOLD",                A_BOLD);
     SetDictInt("A_ALTCHARSET",          A_ALTCHARSET);
-#if !defined(__NetBSD__)
     SetDictInt("A_INVIS",           A_INVIS);
-#endif
     SetDictInt("A_PROTECT",         A_PROTECT);
     SetDictInt("A_CHARTEXT",        A_CHARTEXT);
     SetDictInt("A_COLOR",           A_COLOR);
@@ -3459,7 +3447,6 @@ PyInit__curses(void)
         int key;
         char *key_n;
         char *key_n2;
-#if !defined(__NetBSD__)
         for (key=KEY_MIN;key < KEY_MAX; key++) {
             key_n = (char *)keyname(key);
             if (key_n == NULL || strcmp(key_n,"UNKNOWN KEY")==0)
@@ -3487,7 +3474,6 @@ PyInit__curses(void)
             if (key_n2 != key_n)
                 PyMem_Free(key_n2);
         }
-#endif
         SetDictInt("KEY_MIN", KEY_MIN);
         SetDictInt("KEY_MAX", KEY_MAX);
     }
