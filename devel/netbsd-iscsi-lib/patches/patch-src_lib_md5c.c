$NetBSD: patch-src_lib_md5c.c,v 1.1.2.2 2015/10/24 19:25:36 bsiegert Exp $

--- src/lib/md5c.c.orig	2015-09-12 21:01:19.530772945 +0000
+++ src/lib/md5c.c
@@ -33,17 +33,10 @@
 #include <config.h>
 #endif
 
-#if defined(_KERNEL) || defined(_STANDALONE)
-#include <lib/libkern/libkern.h>
-#include <sys/param.h>
-#include <sys/md5.h>
-#define _DIAGASSERT(x)	(void)0
-#else
 /* #include "namespace.h" */
 #include <assert.h>
 #include <string.h>
 #include "iscsi-md5.h"
-#endif /* _KERNEL || _STANDALONE */
 
 #if defined(HAVE_MEMSET)
 #define	ZEROIZE(d, l)		memset((d), 0, (l))
