$NetBSD: patch-src_sys.h,v 1.2 2023/11/07 10:23:12 nia Exp $

- Include stddef.h/string.h for wchar_t and ssize_t on older Darwin.
- Remove conflicting and unnecessary SunOS-specific defines.

--- src/sys.h.orig	2022-10-30 05:35:40.000000000 +0000
+++ src/sys.h
@@ -80,6 +80,8 @@ typedef void	*ioctl_t;
 #endif
 
 #include <stdio.h>
+#include <stddef.h>
+#include <string.h>
 
 #ifndef HAVE_STRLCAT
 //#define	strlcat libedit_strlcat
@@ -123,13 +125,4 @@ typedef unsigned int	u_int32_t;
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
