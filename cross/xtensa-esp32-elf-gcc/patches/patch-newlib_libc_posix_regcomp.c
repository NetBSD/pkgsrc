$NetBSD: patch-newlib_libc_posix_regcomp.c,v 1.1 2022/04/14 00:50:00 tnn Exp $

work around a problem where _POSIX2_RE_DUP_MAX is undefined

--- newlib/libc/posix/regcomp.c.orig	2022-03-31 06:25:20.000000000 +0000
+++ newlib/libc/posix/regcomp.c
@@ -39,6 +39,7 @@
 static char sccsid[] = "@(#)regcomp.c	8.5 (Berkeley) 3/20/94";
 #endif /* LIBC_SCCS and not lint */
 #include <sys/cdefs.h>
+#include "../include/limits.h"
 
 #include <sys/types.h>
 #include <stdio.h>
