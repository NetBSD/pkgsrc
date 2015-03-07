$NetBSD: patch-cmake_Modules_FindSphinx.cmake,v 1.1 2015/03/07 05:10:45 mef Exp $

(Starting with gnuradio-3.7.6), cmake wants sphinx-build exact executable
name. With SUBST_CLASSES.pyvers in Makefile.common, tell the name.
(The problem without this fix is in gnuradio-doxygen).

--- cmake/Modules/FindSphinx.cmake.orig	2013-05-02 08:57:50.000000000 +0900
+++ cmake/Modules/FindSphinx.cmake	2015-03-06 22:08:44.000000000 +0900
@@ -19,7 +19,7 @@
 # (To distribute this file outside of CMake, substitute the full
 #  License text for the above reference.)
 
-find_program(SPHINX_EXECUTABLE NAMES sphinx-build
+find_program(SPHINX_EXECUTABLE NAMES sphinx-build@PYVERSSUFFIX@
   HINTS
   $ENV{SPHINX_DIR}
   PATH_SUFFIXES bin
