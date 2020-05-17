$NetBSD: patch-libgfortran_io_read.c,v 1.1 2020/05/17 19:47:20 rillig Exp $

Fix -Werror=char-subscripts.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95177

--- libgfortran/io/read.c.orig	2020-05-07 10:50:02.000000000 +0000
+++ libgfortran/io/read.c
@@ -959,7 +959,7 @@ read_f (st_parameter_dt *dtp, const fnod
 	 between "NaN" and the optional perenthesis is not permitted.  */
       while (w > 0)
 	{
-	  *out = tolower (*p);
+	  *out = tolower ((unsigned char) *p);
 	  switch (*p)
 	    {
 	    case ' ':
@@ -981,7 +981,7 @@ read_f (st_parameter_dt *dtp, const fnod
 		goto bad_float;
 	      break;
 	    default:
-	      if (!isalnum (*out))
+	      if (!isalnum ((unsigned char) *out))
 		goto bad_float;
 	    }
 	  --w;
@@ -1109,7 +1109,7 @@ exponent:
 
   if (dtp->u.p.blank_status == BLANK_UNSPECIFIED)
     {
-      while (w > 0 && isdigit (*p))
+      while (w > 0 && isdigit ((unsigned char) *p))
 	{
 	  exponent *= 10;
 	  exponent += *p - '0';
@@ -1137,7 +1137,7 @@ exponent:
 	      else
 		assert (dtp->u.p.blank_status == BLANK_NULL);
 	    }
-	  else if (!isdigit (*p))
+	  else if (!isdigit ((unsigned char) *p))
 	    goto bad_float;
 	  else
 	    {
