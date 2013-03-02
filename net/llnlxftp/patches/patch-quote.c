$NetBSD: patch-quote.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- quote.c.orig	1995-10-19 15:20:24.000000000 +0000
+++ quote.c
@@ -63,6 +63,8 @@
 #include "list.h"
 #include "str.h"
 
+static void create_quote_dialog(void);
+
 struct {
     int host;
     struct entry_link *head;
@@ -194,7 +196,7 @@ XtPointer call_data;
 /*
  * create_quote_dialog - Create dialog that prompts for a quoted command.
  */
-create_quote_dialog()
+static void create_quote_dialog(void)
 {
 	static int initialized = False;
     int i;
