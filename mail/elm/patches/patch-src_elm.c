$NetBSD: patch-src_elm.c,v 1.1 2013/02/26 11:08:17 joerg Exp $

--- src/elm.c.orig	2013-02-25 16:40:15.000000000 +0000
+++ src/elm.c
@@ -63,6 +63,8 @@ static char rcsid[] = "@(#)$Id: elm.c,v 
 #  include <sys/timeb.h>
 #endif
 
+static void debug_message(void);
+
 long bytes();
 char *format_long(), *parse_arguments();
 
@@ -594,7 +596,7 @@ debug_page()
 }
 
 
-debug_message()
+static void debug_message(void)
 {
 	/**** Spit out the current message record.  Include EVERYTHING
 	      in the record structure. **/
