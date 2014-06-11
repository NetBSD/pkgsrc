$NetBSD: patch-Include_pyport.h,v 1.1 2014/06/11 05:55:58 richard Exp $
SunOS defines gethostname in <unistd.h>
http://bugs.python.org/issue19561

--- Include/pyport.h.orig	2014-05-31 18:58:38.000000000 +0000
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
