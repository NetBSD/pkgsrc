$NetBSD: patch-fileop.c,v 1.1 2017/08/04 18:15:05 mrg Exp $

remove a macro-as-prototype failure.

--- fileop.c.orig	2015-01-07 12:43:10.000000000 -0800
+++ fileop.c	2017-08-04 11:05:36.713202977 -0700
@@ -124,7 +124,6 @@
 void file_read(int);
 void splash(void);
 void usage(void);
-void bzero();
 void clear_stats();
 int validate(char *, int , char );
 
