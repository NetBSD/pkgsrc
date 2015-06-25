$NetBSD: patch-unproto_tok__class.c,v 1.1 2015/06/25 07:27:32 dholland Exp $

Use standard headers.

--- unproto/tok_class.c~	2014-03-14 04:33:19.000000000 +0000
+++ unproto/tok_class.c
@@ -49,10 +49,8 @@ static char class_sccsid[] = "@(#) tok_c
 /* C library */
 
 #include <stdio.h>
-
-extern char *strcpy();
-extern long time();
-extern char *ctime();
+#include <string.h>
+#include <time.h>
 
 /* Application-specific stuff */
 
