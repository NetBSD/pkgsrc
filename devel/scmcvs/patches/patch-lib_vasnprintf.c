$NetBSD: patch-lib_vasnprintf.c,v 1.1 2015/04/12 07:43:42 dsainty Exp $

Avoid CVS crashing on systems using _FORTIFY_SOURCE by default.

http://git.savannah.gnu.org/cgit/gnulib.git/commit/lib/vasnprintf.c?id=913c09becd9df89dbd9b9f386e7f35c240d5efe8

--- lib/vasnprintf.c.orig	2005-05-24 05:44:33.000000000 +1200
+++ lib/vasnprintf.c	2015-04-12 18:56:46.352971555 +1200
@@ -558,9 +558,21 @@
 		  }
 		*p = dp->conversion;
 #if USE_SNPRINTF
+# if !(__GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3))
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
+		p[1] = '\0';
+# endif
 #else
 		p[1] = '\0';
 #endif
