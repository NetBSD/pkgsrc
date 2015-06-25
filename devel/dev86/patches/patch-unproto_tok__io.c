$NetBSD: patch-unproto_tok__io.c,v 1.2 2015/06/25 07:27:32 dholland Exp $

- use standard headers
- fix return type

--- unproto/tok_io.c.orig	2014-03-14 04:33:19.000000000 +0000
+++ unproto/tok_io.c
@@ -79,13 +79,10 @@ static char io_sccsid[] = "@(#) tok_io.c
 /* C library */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 
-extern char *strchr();
-extern char *malloc();
-extern char *realloc();
-extern char *strcpy();
-
 /* Application-specific stuff */
 
 #include "token.h"
@@ -189,7 +186,7 @@ static char *ignore_directives[] = {
 
 /* do_control - parse control line */
 
-static int do_control()
+static void do_control(void)
 {
     struct token *t;
     int     line;
