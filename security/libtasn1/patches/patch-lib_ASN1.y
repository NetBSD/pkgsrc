$NetBSD: patch-lib_ASN1.y,v 1.1 2018/04/29 03:41:43 dholland Exp $

Use <ctype.h> correctly.

--- lib/ASN1.y~	2017-01-25 08:45:09.000000000 +0000
+++ lib/ASN1.y
@@ -575,7 +575,7 @@ _asn1_yylex ()
 
       /* Is STRING a number? */
       for (k = 0; k < counter; k++)
-        if (!isdigit ((int)string[k]))
+        if (!isdigit ((unsigned char)string[k]))
           break;
       if (k >= counter)
         {
