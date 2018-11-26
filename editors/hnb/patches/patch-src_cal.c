$NetBSD: patch-src_cal.c,v 1.1 2018/11/26 09:15:53 fox Exp $

In NetBSD-1.6.2, the <stdlib.h> header uses the word bufsize as a
parameter name in a function prototype. The "file.h" header #defines
bufsize to 4096, which leads to a parser error.

Above fix made by rilling on 2005/03/11

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems. 

--- src/cal.c.orig	2003-03-14 01:06:36.000000000 +0000
+++ src/cal.c
@@ -19,15 +19,15 @@
  */
 
 /**************/
+#include <stdlib.h>
+#include <stdio.h>
+#include <time.h>
+
 #include "tree.h"
 #include "cli.h"
 #include "ui.h"
 #include "file.h"
 
-#include <stdlib.h>
-#include <stdio.h>
-#include <time.h>
-
 static char *const wday[] = 
 	{ "Sun", "Mon", "Tue",  "Wed", "Thu", "Fri", "Sat", "   "};
 
@@ -35,7 +35,7 @@
 	  "", "January", "February", "March", "April", "May" ,"June", "July",
 	  "August", "September", "October", "November" , "December"};
 
-static int insert_cal(int argc, char **argv, void *data){
+static uint64_t insert_cal(int argc, char **argv, void *data){
 	Node *pos=(void *)data;
 
 	int year;
@@ -44,7 +44,7 @@
 	
 	if( (argc!=3) || (atoi(argv[1])>12 )){
 		cli_outfunf("usage: %s <month> <year>", argv[0]);
-		return (int)data;
+		return PTR_TO_UINT64(data);
 	}
 
 	month=atoi(argv[1]);
@@ -96,7 +96,7 @@
 		}
 	}	
 
-	return (int)pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
