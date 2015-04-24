$NetBSD: patch-Include_pyport.h,v 1.3 2015/04/24 03:01:36 rodent Exp $

SunOS defines gethostname in <unistd.h>
http://bugs.python.org/issue19561

--- Include/pyport.h.orig	2014-12-10 15:59:32.000000000 +0000
+++ Include/pyport.h
@@ -640,11 +640,6 @@ Please be conservative with adding new o
 in platform-specific #ifdefs.
 **************************************************************************/
 
-#ifdef SOLARIS
-/* Unchecked */
-extern int gethostname(char *, int);
-#endif
-
 #ifdef __BEOS__
 /* Unchecked */
 /* It's in the libs, but not the headers... - [cjh] */
