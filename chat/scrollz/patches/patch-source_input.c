$NetBSD: patch-source_input.c,v 1.1 2015/07/27 22:31:30 wiz Exp $

Fixes incompatible pointer type error.

--- source/input.c.orig	2011-04-29 08:21:18.000000000 +0000
+++ source/input.c
@@ -857,8 +857,8 @@ re_encode:
         else
 /****************************************************************************/
 	retval = iconv(mbdata.conv_in,
-		       &iptr, &isize,
-		       (char **)&optr, &osize);
+		       (const char**)&iptr, &isize,
+		       &optr, &osize);
 	
 	if (retval == (size_t)-1)
 	{
@@ -1010,7 +1010,7 @@ get_input()
 		size_t retval;
 
 		retval = iconv(conv,
-		                &source, &left,
+		                (const char**)&source, &left,
 		                &dest, &space);
 		if (retval == (size_t)-1)
 		{
