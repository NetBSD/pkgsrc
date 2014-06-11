$NetBSD: patch-Include_pyport.h,v 1.1 2014/06/11 06:03:10 richard Exp $
SunOS defines gethostname in <unistd.h>
http://bugs.python.org/issue19561

--- Include/pyport.h.orig	2013-05-15 16:32:54.000000000 +0000
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
