$NetBSD: patch-src_sys.h,v 1.1 2020/04/21 13:07:01 jperkin Exp $

Remove conflicting and unnecessary SunOS-specific defines.

--- src/sys.h.orig	2018-05-25 17:50:45.000000000 +0000
+++ src/sys.h
@@ -115,13 +115,4 @@ typedef unsigned int	u_int32_t;
 #define	REGEX		/* Use POSIX.2 regular expression functions */
 #undef	REGEXP		/* Use UNIX V8 regular expression functions */
 
-#if defined(__sun)
-extern int tgetent(char *, const char *);
-extern int tgetflag(char *);
-extern int tgetnum(char *);
-extern int tputs(const char *, int, int (*)(int));
-extern char* tgoto(const char*, int, int);
-extern char* tgetstr(char*, char**);
-#endif
-
 #endif /* _h_sys */
