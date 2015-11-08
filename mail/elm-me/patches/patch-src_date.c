$NetBSD: patch-src_date.c,v 1.1 2015/11/08 20:42:38 dholland Exp $

- avoid obsolete sys/timeb.h

--- src/date.c~	2001-06-19 17:03:18.000000000 +0000
+++ src/date.c
@@ -18,10 +18,6 @@ static char rcsid[] = "@(#)$Id: date.c,v
 #include "headers.h"
 #include "me.h"
 
-#ifdef BSD_TYPE
-#  include <sys/timeb.h>
-#endif
-
 #ifndef	_POSIX_SOURCE
 extern struct tm *localtime();
 extern struct tm *gmtime();
