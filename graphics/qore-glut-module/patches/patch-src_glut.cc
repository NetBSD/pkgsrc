$NetBSD: patch-src_glut.cc,v 1.2 2016/07/22 13:16:39 nros Exp $
Adapt for the QoreValue api.
Remove duplicate function additions.
--- src/glut.cc.orig	2009-01-23 15:34:09.000000000 +0000
+++ src/glut.cc
@@ -127,7 +127,7 @@ static void qore_glut_menu_callback(int 
    ExceptionSink xsink;
    ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
    args->push(new QoreBigIntNode(value));
-   discard(i->second->exec(*args, &xsink), &xsink);
+   i->second->execValue(*args, &xsink).discard(&xsink);
 }
 
 static void qore_glut_reshape_func(int width, int height)
@@ -139,7 +139,7 @@ static void qore_glut_reshape_func(int w
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(width));
       args->push(new QoreBigIntNode(height));
-      discard(reshape_ref->exec(*args, &xsink), &xsink);
+      reshape_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -149,7 +149,7 @@ static void qore_glut_display_func()
    AutoLocker al(&display_lock);
    if (display_ref) {
       ExceptionSink xsink;
-      discard(display_ref->exec(0, &xsink), &xsink);
+      display_ref->execValue(0, &xsink).discard(&xsink);
    }
 }
 
@@ -163,7 +163,7 @@ static void qore_glut_keyboard_func(unsi
       args->push(new QoreBigIntNode(key));
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(keyboard_ref->exec(*args, &xsink), &xsink);
+      keyboard_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -175,7 +175,7 @@ static void qore_glut_visibility_func(in
       ExceptionSink xsink;
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(state));
-      discard(visibility_ref->exec(*args, &xsink), &xsink);
+      visibility_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -185,7 +185,7 @@ static void qore_glut_idle_func()
    AutoLocker al(&idle_lock);
    if (idle_ref) {
       ExceptionSink xsink;
-      discard(idle_ref->exec(0, &xsink), &xsink);
+      idle_ref->execValue(0, &xsink).discard(&xsink);
    }
 }
 
@@ -199,7 +199,7 @@ static void qore_glut_special_func(int k
       args->push(new QoreBigIntNode(key));
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(special_ref->exec(*args, &xsink), &xsink);
+      special_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -209,7 +209,7 @@ static void qore_glut_wmclose_func()
    AutoLocker al(&wmclose_lock);
    if (wmclose_ref) {
       ExceptionSink xsink;
-      discard(wmclose_ref->exec(0, &xsink), &xsink);
+      wmclose_ref->execValue(0, &xsink).discard(&xsink);
    }
 }
 #endif
@@ -224,7 +224,7 @@ static void qore_glut_mouse_func(int but
       args->push(new QoreBigIntNode(state));
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(mouse_ref->exec(*args, &xsink), &xsink);
+      mouse_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -236,7 +236,7 @@ static void qore_glut_motion_func(int x,
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(motion_ref->exec(*args, &xsink), &xsink);
+      motion_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -248,7 +248,7 @@ static void qore_glut_passivemotion_func
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(passivemotion_ref->exec(*args, &xsink), &xsink);
+      passivemotion_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -259,7 +259,7 @@ static void qore_glut_entry_func(int sta
       ExceptionSink xsink;
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(state));
-      discard(entry_ref->exec(*args, &xsink), &xsink);
+      entry_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -270,7 +270,7 @@ static void qore_glut_timer_func(int val
       ExceptionSink xsink;
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(value));
-      discard(timer_ref->exec(*args, &xsink), &xsink);
+      timer_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -281,7 +281,7 @@ static void qore_glut_menustate_func(int
       ExceptionSink xsink;
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(state));
-      discard(menustate_ref->exec(*args, &xsink), &xsink);
+      menustate_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -294,7 +294,7 @@ static void qore_glut_spaceballmotion_fu
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
       args->push(new QoreBigIntNode(z));
-      discard(spaceballmotion_ref->exec(*args, &xsink), &xsink);
+      spaceballmotion_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -307,7 +307,7 @@ static void qore_glut_spaceballrotate_fu
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
       args->push(new QoreBigIntNode(z));
-      discard(spaceballrotate_ref->exec(*args, &xsink), &xsink);
+      spaceballrotate_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -319,7 +319,7 @@ static void qore_glut_spaceballbutton_fu
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(button));
       args->push(new QoreBigIntNode(state));
-      discard(spaceballbutton_ref->exec(*args, &xsink), &xsink);
+      spaceballbutton_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -331,7 +331,7 @@ static void qore_glut_buttonbox_func(int
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(button));
       args->push(new QoreBigIntNode(state));
-      discard(buttonbox_ref->exec(*args, &xsink), &xsink);
+      buttonbox_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -343,7 +343,7 @@ static void qore_glut_dials_func(int dia
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(dial));
       args->push(new QoreBigIntNode(value));
-      discard(dials_ref->exec(*args, &xsink), &xsink);
+      dials_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -355,7 +355,7 @@ static void qore_glut_tabletmotion_func(
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(tabletmotion_ref->exec(*args, &xsink), &xsink);
+      tabletmotion_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -369,7 +369,7 @@ static void qore_glut_tabletbutton_func(
       args->push(new QoreBigIntNode(state));
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(tabletbutton_ref->exec(*args, &xsink), &xsink);
+      tabletbutton_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -382,7 +382,7 @@ static void qore_glut_menustatus_func(in
       args->push(new QoreBigIntNode(status));
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(menustatus_ref->exec(*args, &xsink), &xsink);
+      menustatus_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -391,7 +391,7 @@ static void qore_glut_overlaydisplay_fun
    AutoLocker al(&overlaydisplay_lock);
    if (overlaydisplay_ref) {
       ExceptionSink xsink;
-      discard(overlaydisplay_ref->exec(0, &xsink), &xsink);
+      overlaydisplay_ref->execValue(0, &xsink).discard(&xsink);
    }
 }
 
@@ -402,7 +402,7 @@ static void qore_glut_windowstatus_func(
       ExceptionSink xsink;
       ReferenceHolder<QoreListNode> args(new QoreListNode(), &xsink);
       args->push(new QoreBigIntNode(state));
-      discard(windowstatus_ref->exec(*args, &xsink), &xsink);
+      windowstatus_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -415,7 +415,7 @@ static void qore_glut_keyboardup_func(un
       args->push(new QoreBigIntNode(key));
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(keyboardup_ref->exec(*args, &xsink), &xsink);
+      keyboardup_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -428,7 +428,7 @@ static void qore_glut_specialup_func(int
       args->push(new QoreBigIntNode(key));
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
-      discard(specialup_ref->exec(*args, &xsink), &xsink);
+      specialup_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -442,7 +442,7 @@ static void qore_glut_joystick_func(unsi
       args->push(new QoreBigIntNode(x));
       args->push(new QoreBigIntNode(y));
       args->push(new QoreBigIntNode(z));
-      discard(joystick_ref->exec(*args, &xsink), &xsink);
+      joystick_ref->execValue(*args, &xsink).discard(&xsink);
    }
 }
 
@@ -1961,18 +1961,12 @@ static QoreStringNode *glut_module_init(
    builtinFunctions.add("glutRemoveMenuItem",           f_glutRemoveMenuItem, QDOM_GUI);
    builtinFunctions.add("glutAttachMenu",               f_glutAttachMenu, QDOM_GUI);
    builtinFunctions.add("glutDetachMenu",               f_glutDetachMenu, QDOM_GUI);
-   builtinFunctions.add("glutDisplayFunc",              f_glutDisplayFunc, QDOM_GUI);
-   builtinFunctions.add("glutReshapeFunc",              f_glutReshapeFunc, QDOM_GUI);
-   builtinFunctions.add("glutKeyboardFunc",             f_glutKeyboardFunc, QDOM_GUI);
    builtinFunctions.add("glutMouseFunc",                f_glutMouseFunc, QDOM_GUI);
    builtinFunctions.add("glutMotionFunc",               f_glutMotionFunc, QDOM_GUI);
    builtinFunctions.add("glutPassiveMotionFunc",        f_glutPassiveMotionFunc, QDOM_GUI);
    builtinFunctions.add("glutEntryFunc",                f_glutEntryFunc, QDOM_GUI);
-   builtinFunctions.add("glutVisibilityFunc",           f_glutVisibilityFunc, QDOM_GUI);
-   builtinFunctions.add("glutIdleFunc",                 f_glutIdleFunc, QDOM_GUI);
    builtinFunctions.add("glutTimerFunc",                f_glutTimerFunc, QDOM_GUI);
    builtinFunctions.add("glutMenuStateFunc",            f_glutMenuStateFunc, QDOM_GUI);
-   builtinFunctions.add("glutSpecialFunc",              f_glutSpecialFunc, QDOM_GUI);
    builtinFunctions.add("glutSpaceballMotionFunc",      f_glutSpaceballMotionFunc, QDOM_GUI);
    builtinFunctions.add("glutSpaceballRotateFunc",      f_glutSpaceballRotateFunc, QDOM_GUI);
    builtinFunctions.add("glutSpaceballButtonFunc",      f_glutSpaceballButtonFunc, QDOM_GUI);
