$NetBSD: patch-lib_computil.c,v 1.2 2015/12/29 23:34:43 dholland Exp $

Avoid symbol name conflict with strtoi.

--- lib/computil.c.orig	2015-01-24 16:18:51.000000000 +0000
+++ lib/computil.c
@@ -614,7 +614,7 @@ TYPES resulttype(TYPES a, TYPES b)
    return(ints);
 }  /* resulttype */
 
-unsigned int strtoi(char *str, int base)
+unsigned int my_strtoi(char *str, int base)
 /* 
    interprets 'str' string as an unsigned integer in the base 'base'
    for 'base' == 2, 8, 10, or 16
@@ -678,7 +678,7 @@ unsigned int tmp=0;
       break;
    }  /* switch */
    return (tmp);
-}  /*end of strtoi */
+}  /*end of my_strtoi */
 
 
 int store_string(char * str, int* sx)
