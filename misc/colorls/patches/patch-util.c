$NetBSD: patch-util.c,v 1.1 2015/07/09 11:44:09 jperkin Exp $

Use nbcompat.

--- util.c.orig	1996-12-21 23:40:58.000000000 +0000
+++ util.c
@@ -44,7 +44,12 @@ static char const sccsid[] = "@(#)util.c
 #include <sys/stat.h>
 
 #include <ctype.h>
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/fts.h>
+#else
 #include <fts.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
