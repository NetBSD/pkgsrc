$NetBSD: patch-src_glut.cc,v 1.1 2014/12/30 15:58:21 wiz Exp $
Remove duplicate function additions.
This is fixed in the svn version of this packege 
so remove this patch on the next update.
--- src/glut.cc.orig	2009-01-23 15:34:09.000000000 +0000
+++ src/glut.cc
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
