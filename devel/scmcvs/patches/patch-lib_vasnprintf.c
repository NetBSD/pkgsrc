$NetBSD: patch-lib_vasnprintf.c,v 1.2 2017/08/18 21:41:19 adam Exp $

Avoid CVS crashing on systems using _FORTIFY_SOURCE by default.
http://git.savannah.gnu.org/cgit/gnulib.git/commit/lib/vasnprintf.c?id=913c09becd9df89dbd9b9f386e7f35c240d5efe8

Fix crash on macOS 10.13 (Darwin 7).
http://git.savannah.gnu.org/cgit/gnulib.git/commit/lib/vasnprintf.c?id=7df04f9b8a0adb1575ca0555775ec10860143cbf

--- lib/vasnprintf.c.orig	2005-05-23 17:44:33.000000000 +0000
+++ lib/vasnprintf.c
@@ -558,9 +558,29 @@ VASNPRINTF (CHAR_T *resultbuf, size_t *l
 		  }
 		*p = dp->conversion;
 #if USE_SNPRINTF
+# if !(__GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3) \
+	|| (defined __APPLE__ && defined __MACH__))
 		p[1] = '%';
 		p[2] = 'n';
 		p[3] = '\0';
+# else
+		/* On glibc2 systems from glibc >= 2.3 - probably also older
+		   ones - we know that snprintf's returns value conforms to
+		   ISO C 99: the gl_SNPRINTF_DIRECTIVE_N test passes.
+		   Therefore we can avoid using %n in this situation.
+		   On glibc2 systems from 2004-10-18 or newer, the use of %n
+		   in format strings in writable memory may crash the program
+		   (if compiled with _FORTIFY_SOURCE=2), so we should avoid it
+		   in this situation.  */
+		/* On Mac OS X 10.3 or newer, we know that snprintf's return
+		   value conforms to ISO C 99: the tests gl_SNPRINTF_RETVAL_C99
+		   and gl_SNPRINTF_TRUNCATION_C99 pass.
+		   Therefore we can avoid using %n in this situation.
+		   On Mac OS X 10.13 or newer, the use of %n in format strings
+		   in writable memory by default crashes the program, so we
+		   should avoid it in this situation.  */
+		p[1] = '\0';
+# endif
 #else
 		p[1] = '\0';
 #endif
