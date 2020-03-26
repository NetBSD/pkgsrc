$NetBSD: patch-unzoo.c,v 1.1 2020/03/26 22:29:47 rillig Exp $

unzoo.c: In function 'IsMatchName':
unzoo.c:1268:40: error: array subscript has type 'char' [-Werror=char-subscripts]
         else if ( *pat=='?' && ! IsSpec[*str] ) { pat++;       str++;       }
                                        ^
unzoo.c:1271:40: error: array subscript has type 'char' [-Werror=char-subscripts]
         else if ( tmp != 0  && ! IsSpec[*tmp] ) { pat =   pos; str = ++tmp; }
                                        ^

This looks indeed like undefined behavior since the function IsMatchName
accepts arbitrary filenames, and filenames containing non-ASCII
characters would access the array outside of its bounds.

On NetBSD-8.0-x86_64 using GCC 5.5.0 the memory below IsSpec is BufArch,
which means that pattern matching depended on the contents of the archive
before.

--- unzoo.c.orig	2020-03-26 22:01:16.074248902 +0000
+++ unzoo.c
@@ -244,6 +244,7 @@
 *H
 */
 #include        <stdio.h>
+#include	<string.h>
 
 
 /****************************************************************************
@@ -1265,10 +1266,10 @@ int             IsMatchName ( pat, str )
     /* try to match the name part                                          */
     while ( *pat != '\0' || *str != '\0' ) {
         if      ( *pat==*str                  ) { pat++;       str++;       }
-        else if ( *pat=='?' && ! IsSpec[*str] ) { pat++;       str++;       }
+        else if ( *pat=='?' && ! IsSpec[(unsigned char) *str] ) { pat++;       str++;       }
         else if ( *pat=='?' && *str != '\0'   ) { pat++;       str++;       }
         else if ( *pat=='*'                   ) { pos = ++pat; tmp =   str; }
-        else if ( tmp != 0  && ! IsSpec[*tmp] ) { pat =   pos; str = ++tmp; }
+        else if ( tmp != 0  && ! IsSpec[(unsigned char) *tmp] ) { pat =   pos; str = ++tmp; }
         else                                    break;
     }
     return *pat == '\0' && *str == '\0';
