$NetBSD: patch-cmake_oiio__macros.cmake,v 1.1 2012/12/03 12:54:14 ryoon Exp $

* Set python interpreter as pkgsrc-provided one

--- cmake/oiio_macros.cmake.orig	2012-11-16 23:02:42.000000000 +0000
+++ cmake/oiio_macros.cmake
@@ -103,7 +103,7 @@ macro (oiio_add_tests)
             if (_has_generator_expr)
                 set (_add_test_args NAME ${_testname} 
 #                                    WORKING_DIRECTORY ${_testdir}
-                                    COMMAND python)
+                                    COMMAND ${PYTHONBIN})
                 if (MSVC_IDE)
                     set (_extra_test_args
                         --devenv-config $<CONFIGURATION>
@@ -112,7 +112,7 @@ macro (oiio_add_tests)
                     set (_extra_test_args "")
                 endif ()
             else ()
-                set (_add_test_args ${_testname} python)
+                set (_add_test_args ${_testname} ${PYTHONBIN})
                 set (_extra_test_args "")
             endif ()
             if (VERBOSE)
