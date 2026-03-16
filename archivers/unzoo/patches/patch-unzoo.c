$NetBSD: patch-unzoo.c,v 1.2 2026/03/16 12:10:21 nia Exp $

Fix implicit declaration of mkdir, utime.

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

--- unzoo.c.orig	2026-03-16 11:45:18.028989167 +0000
+++ unzoo.c
@@ -243,7 +243,11 @@
 *H  Initial revision
 *H
 */
+#include        <sys/types.h>
+#include        <sys/stat.h>
 #include        <stdio.h>
+#include        <string.h>
+#include        <utime.h>
 
 
 /****************************************************************************
@@ -1265,10 +1269,10 @@ int             IsMatchName ( pat, str )
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
