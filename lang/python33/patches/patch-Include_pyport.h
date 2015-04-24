$NetBSD: patch-Include_pyport.h,v 1.2 2015/04/24 03:24:32 rodent Exp $
SunOS defines gethostname in <unistd.h>
http://bugs.python.org/issue19561

--- Include/pyport.h.orig	2014-10-12 07:03:52.000000000 +0000
+++ Include/pyport.h
@@ -649,11 +649,6 @@ Please be conservative with adding new o
 in platform-specific #ifdefs.
 **************************************************************************/
 
-#ifdef SOLARIS
-/* Unchecked */
-extern int gethostname(char *, int);
-#endif
-
 #ifdef HAVE__GETPTY
 #include <sys/types.h>          /* we need to import mode_t */
 extern char * _getpty(int *, int, mode_t, int);
