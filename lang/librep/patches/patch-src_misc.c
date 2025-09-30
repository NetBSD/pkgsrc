$NetBSD: patch-src_misc.c,v 1.1 2025/09/30 14:29:17 gutteridge Exp $

Use ctype.h correctly.

--- src/misc.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ src/misc.c
@@ -112,8 +112,8 @@ strncasecmp (const char *s1, const char 
 
   do
     {
-      c1 = tolower (*p1++);
-      c2 = tolower (*p2++);
+      c1 = tolower ((unsigned char)*p1++);
+      c2 = tolower ((unsigned char)*p2++);
       if (c1 == '\0' || c1 != c2)
         return c1 - c2;
     } while (--n > 0);
@@ -190,7 +190,7 @@ is t, all matching ignores character cas
 		    {
 			if(rep_NILP(fold)
 			   ? (*tmp2 != *tmp)
-			   : (tolower(*tmp2) != tolower(*tmp)))
+			   : (tolower((unsigned char)*tmp2) != tolower((unsigned char)*tmp)))
 			{
 			    break;
 			}
@@ -446,7 +446,7 @@ alpha-char-p CHAR
 Returns t if CHAR is an alphabetic character.
 ::end:: */
 {
-    return (rep_INTP(ch) && isalpha(rep_INT(ch))) ? Qt : Qnil;
+    return (rep_INTP(ch) && isalpha((unsigned char)rep_INT(ch))) ? Qt : Qnil;
 }
 
 DEFUN("upper-case-p", Fupper_case_p, Supper_case_p, (repv ch), rep_Subr1) /*
@@ -456,7 +456,7 @@ upper-case-p CHAR
 Returns t if CHAR is upper case.
 ::end:: */
 {
-    return (rep_INTP(ch) && isupper(rep_INT(ch))) ? Qt : Qnil;
+    return (rep_INTP(ch) && isupper((unsigned char)rep_INT(ch))) ? Qt : Qnil;
 }
 
 DEFUN("lower-case-p", Flower_case_p, Slower_case_p, (repv ch), rep_Subr1) /*
@@ -466,7 +466,7 @@ lower-case-p CHAR
 Returns t if CHAR is lower case.
 ::end:: */
 {
-    return (rep_INTP(ch) && islower(rep_INT(ch))) ? Qt : Qnil;
+    return (rep_INTP(ch) && islower((unsigned char)rep_INT(ch))) ? Qt : Qnil;
 }
 
 DEFUN("digit-char-p", Fdigit_char_p, Sdigit_char_p, (repv ch), rep_Subr1) /*
@@ -476,7 +476,7 @@ digit-char-p CHAR
 Returns t if CHAR is a digit.
 ::end:: */
 {
-    return (rep_INTP(ch) && isdigit(rep_INT(ch))) ? Qt : Qnil;
+    return (rep_INTP(ch) && isdigit((unsigned char)rep_INT(ch))) ? Qt : Qnil;
 }
 
 DEFUN("alphanumericp", Falphanumericp, Salphanumericp, (repv ch), rep_Subr1) /*
@@ -486,7 +486,7 @@ alphanumericp CHAR
 Returns t if CHAR is alpha-numeric.
 ::end:: */
 {
-    return (rep_INTP(ch) && isalnum(rep_INT(ch))) ? Qt : Qnil;
+    return (rep_INTP(ch) && isalnum((unsigned char)rep_INT(ch))) ? Qt : Qnil;
 }
 
 DEFUN("space-char-p", Fspace_char_p, Sspace_char_p, (repv ch), rep_Subr1) /*
@@ -496,7 +496,7 @@ space-char-p CHAR
 Returns t if CHAR is whitespace.
 ::end:: */
 {
-    return (rep_INTP(ch) && isspace(rep_INT(ch))) ? Qt : Qnil;
+    return (rep_INTP(ch) && isspace((unsigned char)rep_INT(ch))) ? Qt : Qnil;
 }
 
 DEFUN("char-upcase", Fchar_upcase, Schar_upcase, (repv ch), rep_Subr1) /*
@@ -507,7 +507,7 @@ Returns the upper-case equivalent of CHA
 ::end:: */
 {
     rep_DECLARE1(ch, rep_INTP);
-    return rep_MAKE_INT(toupper(rep_INT(ch)));
+    return rep_MAKE_INT(toupper((unsigned char)rep_INT(ch)));
 }
 
 DEFUN("char-downcase", Fchar_downcase, Schar_downcase, (repv ch), rep_Subr1) /*
@@ -518,7 +518,7 @@ Returns the lower-case equivalent of CHA
 ::end:: */
 {
     rep_DECLARE1(ch, rep_INTP);
-    return rep_MAKE_INT(tolower(rep_INT(ch)));
+    return rep_MAKE_INT(tolower((unsigned char)rep_INT(ch)));
 }
 
 DEFUN_INT("system", Fsystem, Ssystem, (repv command), rep_Subr1, "sShell command:") /*
@@ -648,8 +648,8 @@ rep_misc_init(void)
 
 	for(i = 0; i < 256; i++)
 	{
-	    ((unsigned char *)rep_STR(up))[i] = toupper(i);
-	    ((unsigned char *)rep_STR(down))[i] = tolower(i);
+	    ((unsigned char *)rep_STR(up))[i] = toupper((unsigned char)i);
+	    ((unsigned char *)rep_STR(down))[i] = tolower((unsigned char)i);
 	}
 	rep_STR(up)[256] = 0;
 	rep_STR(down)[256] = 0;
