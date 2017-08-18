$NetBSD: patch-lib_vasnprintf.c,v 1.1 2017/08/18 21:43:03 adam Exp $

Fix crash on macOS 10.13 (Darwin 17).
http://git.savannah.gnu.org/cgit/gnulib.git/commit/lib/vasnprintf.c?id=7df04f9b8a0adb1575ca0555775ec10860143cbf

--- lib/vasnprintf.c.orig	2015-01-04 16:46:03.000000000 +0000
+++ lib/vasnprintf.c
@@ -4858,7 +4869,10 @@ VASNPRINTF (DCHAR_T *resultbuf, size_t *
 #endif
                   *fbp = dp->conversion;
 #if USE_SNPRINTF
-# if !(((__GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3)) && !defined __UCLIBC__) || ((defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__))
+# if ! (((__GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3))        \
+         && !defined __UCLIBC__)                                            \
+        || (defined __APPLE__ && defined __MACH__)                          \
+        || ((defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__))
                 fbp[1] = '%';
                 fbp[2] = 'n';
                 fbp[3] = '\0';
@@ -4872,6 +4886,13 @@ VASNPRINTF (DCHAR_T *resultbuf, size_t *
                    in format strings in writable memory may crash the program
                    (if compiled with _FORTIFY_SOURCE=2), so we should avoid it
                    in this situation.  */
+                /* On Mac OS X 10.3 or newer, we know that snprintf's return
+                   value conforms to ISO C 99: the tests gl_SNPRINTF_RETVAL_C99
+                   and gl_SNPRINTF_TRUNCATION_C99 pass.
+                   Therefore we can avoid using %n in this situation.
+                   On Mac OS X 10.13 or newer, the use of %n in format strings
+                   in writable memory by default crashes the program, so we
+                   should avoid it in this situation.  */
                 /* On native Windows systems (such as mingw), we can avoid using
                    %n because:
                      - Although the gl_SNPRINTF_TRUNCATION_C99 test fails,
