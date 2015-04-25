$NetBSD: patch-squint_main.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Muck with fmtinstall to avoid doing undefined/illegal things with va_list.

--- squint/main.c~	2000-02-11 17:04:43.000000000 +0000
+++ squint/main.c
@@ -4,16 +4,16 @@
 #include <bio.h>
 #include "fns.h"
 
-extern int	bconv(va_list *, Fconv*);
-extern int	econv(va_list *, Fconv*);
-extern int	iconv(va_list *, Fconv*);
-extern int	mconv(va_list *, Fconv*);
-extern int	nconv(va_list *, Fconv*);
-extern int	tconv(va_list *, Fconv*);
-extern int	Aconv(va_list *, Fconv*);
-extern int	Cconv(va_list *, Fconv*);
-extern int	Uconv(va_list *, Fconv*);
-extern int	zconv(va_list *, Fconv*);
+extern int	bconv(struct va_wrap *, Fconv*);
+extern int	econv(struct va_wrap *, Fconv*);
+extern int	iconv(struct va_wrap *, Fconv*);
+extern int	mconv(struct va_wrap *, Fconv*);
+extern int	nconv(struct va_wrap *, Fconv*);
+extern int	tconv(struct va_wrap *, Fconv*);
+extern int	Aconv(struct va_wrap *, Fconv*);
+extern int	Cconv(struct va_wrap *, Fconv*);
+extern int	Uconv(struct va_wrap *, Fconv*);
+extern int	zconv(struct va_wrap *, Fconv*);
 
 int		bflag;
 int		cflag;
