$NetBSD: patch-stat__flags.c,v 1.2 2015/07/09 11:44:09 jperkin Exp $

Avoid file flags on SunOS.

--- stat_flags.c.orig	1996-12-21 23:40:58.000000000 +0000
+++ stat_flags.c
@@ -43,6 +43,8 @@ static char const sccsid[] = "@(#)stat_f
 #include <stddef.h>
 #include <string.h>
 
+#ifndef __sun
+
 #define	SAPPEND(s) {							\
 	if (prefix != NULL)						\
 		(void)strcat(string, prefix);				\
@@ -153,3 +155,4 @@ string_to_flags(stringp, setp, clrp)
 	}
 	return (0);
 }
+#endif /* __sun */
