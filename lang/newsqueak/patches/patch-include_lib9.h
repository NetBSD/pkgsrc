$NetBSD: patch-include_lib9.h,v 1.1 2015/04/25 19:58:32 dholland Exp $

Provide an implementation of SET to silence some compiler warnings.
Muck with fmtinstall to avoid doing undefined/illegal things with va_list.

--- include/lib9.h~	2000-02-11 17:04:14.000000000 +0000
+++ include/lib9.h
@@ -7,7 +7,7 @@ typedef unsigned short Rune;
 #define	create(name, mode, perm)	creat(name, perm)
 #define	exec(a,b)			execv(a,b)
 #define	USED(a)
-#define SET(a)
+#define SET(a)				((a) = 0)
 
 #define nil ((void*)0)
 
@@ -96,7 +96,10 @@ int	sprint(char *buf, const char *fmt, .
 int	snprint(char *buf, int len, const char *fmt, ...);
 char*	seprint(char *buf, char *e, const char *fmt, ...);
 #define pow10(n) (pow(10.0, (double)(n)))
-extern	int	fmtinstall(int, int (*)(va_list*, Fconv*));
+struct va_wrap {
+	va_list ap;
+};
+extern	int	fmtinstall(int, int (*)(struct va_wrap *, Fconv*));
 
 /* nan.c */
 double	NaN(void);
