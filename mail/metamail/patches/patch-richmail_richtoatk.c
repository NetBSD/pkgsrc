$NetBSD: patch-richmail_richtoatk.c,v 1.1 2025/10/12 00:57:39 mrg Exp $

Port for GCC 14.

--- richmail/richtoatk.c.orig	1994-02-02 18:28:18.000000000 -0800
+++ richmail/richtoatk.c	2025-10-11 17:53:00.230274649 -0700
@@ -14,8 +14,11 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 */
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 #include "richlex.h"
 
+int ignoretoken();
+
 char *translate(t)
 char *t;
 {
@@ -25,6 +28,7 @@ char *t;
     return(t);
 }
 
+void
 main() {
     RCHAR c;
     int i, JustDidNewline = 0;
@@ -76,6 +80,7 @@ main() {
     fputs("\n \n\\enddata{text, 42}\n", stdout);
 }
 
+int
 ignoretoken(t)
 char *t;
 {
@@ -86,11 +91,13 @@ char *t;
     return(0);
 }
 
+int
 controlputc(c)
 int c;
 {
 }
 
+int
 controloutput(s, immediate)
 char *s;
 int immediate;
