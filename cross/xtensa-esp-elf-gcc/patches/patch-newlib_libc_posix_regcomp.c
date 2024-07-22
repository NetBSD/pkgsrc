$NetBSD: patch-newlib_libc_posix_regcomp.c,v 1.1 2024/07/22 20:01:50 tnn Exp $

work around a problem where _POSIX2_RE_DUP_MAX is undefined

--- newlib/libc/posix/regcomp.c.orig	2024-07-20 16:19:51.128168994 +0000
+++ newlib/libc/posix/regcomp.c
@@ -39,6 +39,7 @@
 static char sccsid[] = "@(#)regcomp.c	8.5 (Berkeley) 3/20/94";
 #endif /* LIBC_SCCS and not lint */
 #include <sys/cdefs.h>
+#include "../include/limits.h"
 
 #include <sys/types.h>
 #include <stdio.h>
