$NetBSD: patch-unproto_strsave.c,v 1.1 2025/12/17 10:55:53 prlw1 Exp $

Fix build:
- conflicting types for built-in function 'malloc'
- implicit declaration of function 'strlen', 'strcmp' and 'hash'

--- unproto/strsave.c.orig	2014-03-14 04:33:19.000000000 +0000
+++ unproto/strsave.c
@@ -26,13 +26,15 @@ static char strsave_sccsid[] = "@(#) str
 
 /* C library */
 
-extern char *strcpy();
-extern char *malloc();
+#include <stdlib.h>
+#include <string.h>
 
 /* Application-specific stuff */
 
 #include "error.h"
 
+int hash(register char *, unsigned); /* hash.c */
+
 #define	STR_TABSIZE	100
 
 struct string {
