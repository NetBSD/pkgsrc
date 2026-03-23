$NetBSD: patch-wmxmms_getopt.c,v 1.1 2026/03/23 13:11:30 nia Exp $

Fix implicit declaration of string functions. With modern GCC this
is worse than potentially having "special magic macros that don't work
in GCC" (unlikely to exist in any unix made after the 20th century).

--- wmxmms/getopt.c.orig	1999-07-29 21:03:12.000000000 +0000
+++ wmxmms/getopt.c
@@ -198,48 +198,15 @@ ordering;
 /* Value of POSIXLY_CORRECT environment variable.  */
 static char *posixly_correct;
 
-#ifdef	__GNU_LIBRARY__
-/* We want to avoid inclusion of string.h with non-GNU libraries
-   because there are many ways it can cause trouble.
-   On some systems, it contains special magic macros that don't work
-   in GCC.  */
+
 #include <string.h>
 #define	my_index	strchr
-#else
 
 /* Avoid depending on library functions or files
    whose names are inconsistent.  */
 
 char *getenv();
 
-static char *
-     my_index(str, chr)
-     const char *str;
-     int chr;
-{
-	while (*str)
-	{
-		if (*str == chr)
-			return (char *) str;
-		str++;
-	}
-	return 0;
-}
-
-/* If using GCC, we can safely declare strlen this way.
-   If not using GCC, it is ok not to declare it.  */
-#ifdef __GNUC__
-/* Note that Motorola Delta 68k R3V7 comes with GCC but not stddef.h.
-   That was relevant to code that was here before.  */
-#if !defined (__STDC__) || !__STDC__
-/* gcc with -traditional declares the built-in strlen to return int,
-   and has done so at least since version 2.4.5. -- rms.  */
-extern int strlen(const char *);
-
-#endif /* not __STDC__ */
-#endif /* __GNUC__ */
-
-#endif /* not __GNU_LIBRARY__ */
 
 /* Handle permutation of arguments.  */
 
