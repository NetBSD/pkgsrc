$NetBSD: patch-external_getopt.h,v 1.1 2012/10/20 22:08:32 joerg Exp $

--- external/getopt.h.orig	2003-01-21 21:19:38.000000000 +0000
+++ external/getopt.h
@@ -100,21 +100,6 @@ struct option
 #define optional_argument	2
 
 #if defined (__STDC__) && __STDC__
-/* HAVE_DECL_* is a three-state macro: undefined, 0 or 1.  If it is
-   undefined, we haven't run the autoconf check so provide the
-   declaration without arguments.  If it is 0, we checked and failed
-   to find the declaration so provide a fully prototyped one.  If it
-   is 1, we found it so don't provide any declaration at all.  */
-#if defined (__GNU_LIBRARY__) || (defined (HAVE_DECL_GETOPT) && !HAVE_DECL_GETOPT)
-/* Many other libraries have conflicting prototypes for getopt, with
-   differences in the consts, in stdlib.h.  To avoid compilation
-   errors, only prototype getopt for the GNU C library.  */
-extern int getopt (int argc, char *const *argv, const char *shortopts);
-#else /* not __GNU_LIBRARY__ */
-# if !defined (HAVE_DECL_GETOPT)
-extern int getopt ();
-# endif
-#endif /* __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);
 extern int getopt_long_only (int argc, char *const *argv,
