$NetBSD: patch-cmp.c,v 1.1 2015/07/09 11:44:09 jperkin Exp $

Use nbcompat.

--- cmp.c.orig	1997-01-02 06:25:13.000000000 +0000
+++ cmp.c
@@ -43,7 +43,12 @@ static char const sccsid[] = "@(#)cmp.c
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/fts.h>
+#else
 #include <fts.h>
+#endif
 #include <string.h>
 
 #include "ls.h"
