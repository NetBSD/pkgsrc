$NetBSD: patch-stat__flags.c,v 1.1 2012/03/01 16:25:16 hans Exp $

--- stat_flags.c.orig	1996-12-22 00:40:58.000000000 +0100
+++ stat_flags.c	2012-03-01 15:39:46.769141152 +0100
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
