$NetBSD: patch-Wnn_etc_getopt.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Include necessary headers that won't cause conflict with getopt
- Remove unnecessary old stype declarations for standard C functions

--- Wnn/etc/getopt.c.orig	2003-05-11 18:37:56.000000000 +0000
+++ Wnn/etc/getopt.c
@@ -62,15 +62,12 @@
 
 #ifndef ELIDE_CODE
 
-
-/* This needs to come after some library #include
-   to get __GNU_LIBRARY__ defined.  */
-#ifdef	__GNU_LIBRARY__
-/* Don't include stdlib.h for non-GNU C libraries because some of them
-   contain conflicting prototypes for getopt.  */
+#ifdef HAVE_STDLIB_H
 # include <stdlib.h>
+#endif
+#ifdef HAVE_UNISTD_H
 # include <unistd.h>
-#endif	/* GNU C library.  */
+#endif
 
 #ifdef VMS
 # include <unixlib.h>
@@ -212,10 +209,6 @@ static char *posixly_correct;
 /* Avoid depending on library functions or files
    whose names are inconsistent.  */
 
-#ifndef getenv
-extern char *getenv ();
-#endif
-
 static char *
 my_index (str, chr)
      const char *str;
@@ -230,18 +223,6 @@ my_index (str, chr)
   return 0;
 }
 
-/* If using GCC, we can safely declare strlen this way.
-   If not using GCC, it is ok not to declare it.  */
-#ifdef __GNUC__
-/* Note that Motorola Delta 68k R3V7 comes with GCC but not stddef.h.
-   That was relevant to code that was here before.  */
-# if (!defined __STDC__ || !__STDC__) && !defined strlen
-/* gcc with -traditional declares the built-in strlen to return int,
-   and has done so at least since version 2.4.5. -- rms.  */
-extern int strlen (const char *);
-# endif /* not __STDC__ */
-#endif /* __GNUC__ */
-
 #endif /* not __GNU_LIBRARY__ */
 
 /* Handle permutation of arguments.  */
