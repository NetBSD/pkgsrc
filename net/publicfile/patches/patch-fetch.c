$NetBSD: patch-fetch.c,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- fetch.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ fetch.c
@@ -8,6 +8,8 @@
 #include "direntry.h"
 #include "fmt.h"
 #include "fetch.h"
+#include "readwrite.h"
+#include "open.h"
 
 int fetch_ascii = 1;
 unsigned long fetch_rest = 0;
@@ -75,14 +77,14 @@ static void list(char *fn,int flaglong)
       if (error_temp(errno)) _exit(23);
       return;
     }
-    printstat(&st);
+    printstat();
   }
 
   substdio_puts(&ss,fn);
   substdio_puts(&ss,"\r\n");
 }
 
-static int doit(char *fn,int fddata,int fdfile,int how)
+static void doit(char *fn,int fddata,int fdfile,int how)
 {
   DIR *dir;
   direntry *d;
@@ -94,7 +96,7 @@ static int doit(char *fn,int fddata,int 
   switch(how) {
     case FETCH_LISTONE:
       if (fstat(fdfile,&st) == -1) break;
-      printstat(&st);
+      printstat();
       for (i = 0;fn[i];++i)
 	if (fn[i] == '\n')
 	  substdio_put(&ss,"",1);
