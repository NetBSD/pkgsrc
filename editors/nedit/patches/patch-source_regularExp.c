$NetBSD: patch-source_regularExp.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Don't use NULL as an integer constant.

--- source/regularExp.c~	2004-08-20 16:37:30.000000000 +0000
+++ source/regularExp.c
@@ -4092,7 +4092,7 @@ static unsigned char * makeDelimiterTabl
       table [*c] = 1;
    }
 
-   table [(int) NULL] = 1; /* These       */
+   table [(int) '\0'] = 1; /* These       */
    table [(int) '\t'] = 1; /* characters  */
    table [(int) '\n'] = 1; /* are always  */
    table [(int) ' ' ] = 1; /* delimiters. */
