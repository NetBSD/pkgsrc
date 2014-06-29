$NetBSD: patch-makelist.c,v 1.1 2014/06/29 03:24:33 dholland Exp $

initialize uninitialized variable, found by gcc 4.5

--- makelist.c~	1991-07-16 15:52:17.000000000 +0000
+++ makelist.c
@@ -53,7 +53,9 @@ int *longest;        /* length of longes
 #endif
 
    int gap;                /* for Shell sort */
-   
+
+   this_path = NULL;
+
    flistsize--;            /* allow for one terminating NULL entry */
    fptr = *longest = 0;
 
