$NetBSD: patch-output.c,v 1.1 2016/07/27 20:37:27 kamil Exp $

Fix K&R code.

--- output.c.orig	2016-07-27 20:12:55.351278093 +0000
+++ output.c
@@ -24,8 +24,8 @@ char output_RCSid[] = "Revision: 1.5 $";
 
 #include "agm.h"
 
-print_prevs (percent)
-     int percent;
+void
+print_prevs (int percent)
 {
   int loop;
 
@@ -46,8 +46,8 @@ print_prevs (percent)
   spos += totlen + prevcount + 1;
 }
 
-list_dictionary (p)
-  struct wnode *p;
+void
+list_dictionary (struct wnode *p)
 {
   while (p != NULL) {
     puts (p->word);
