$NetBSD: patch-tree.h,v 1.2 2013/08/25 14:29:52 richard Exp $

* solaris defines S_ISDOOR already so undef in order to not
* undermine program logic.
*
--- tree.h.orig	2011-06-24 12:55:58.000000000 +0000
+++ tree.h
@@ -59,6 +59,10 @@
 #define mbstowcs(w,m,x) mbsrtowcs(w,(const char**)(& #m),x,NULL)
 #endif
 
+#ifdef __sun
+# undef S_ISDOOR
+#endif
+
 /* Should probably use strdup(), but we like our xmalloc() */
 #define scopy(x)	strcpy(xmalloc(strlen(x)+1),(x))
 #define MINIT		30	/* number of dir entries to initially allocate */
