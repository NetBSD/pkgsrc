$NetBSD: patch-lib_verror.h,v 1.1 2012/04/27 21:01:41 wiz Exp $

2011-03-20  Bruno Haible  <bruno@clisp.org>

       verror: Fix compilation error introduced on 2011-02-13.
       * lib/verror.h (verror, verror_at_line): Use _GL_ATTRIBUTE_FORMAT macro
       instead of __attribute__.
       Reported by Tom G. Christensen <tgc@jupiterrise.com>.

--- lib/verror.h.orig	2011-03-01 16:39:30.000000000 +0000
+++ lib/verror.h
@@ -17,9 +17,10 @@
 #ifndef _VERROR_H
 #define _VERROR_H 1
 
-#include "error.h"
 #include <stdarg.h>
 
+#include "error.h" /* for _GL_ATTRIBUTE_FORMAT */
+
 #ifdef __cplusplus
 extern "C" {
 #endif
@@ -32,7 +33,7 @@ extern "C" {
 
 extern void verror (int __status, int __errnum, const char *__format,
                     va_list __args)
-     __attribute__ ((__format__ (__printf__, 3, 0)));
+     _GL_ATTRIBUTE_FORMAT ((__printf__, 3, 0));
 
 /* Print a message with `vfprintf (stderr, FORMAT, ARGS)';
    if ERRNUM is nonzero, follow it with ": " and strerror (ERRNUM).
@@ -44,7 +45,7 @@ extern void verror (int __status, int __
 extern void verror_at_line (int __status, int __errnum, const char *__fname,
                             unsigned int __lineno, const char *__format,
                             va_list __args)
-     __attribute__ ((__format__ (__printf__, 5, 0)));
+     _GL_ATTRIBUTE_FORMAT ((__printf__, 5, 0));
 
 #ifdef __cplusplus
 }
