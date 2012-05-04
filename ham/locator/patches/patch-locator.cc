$NetBSD: patch-locator.cc,v 1.2 2012/05/04 16:19:37 joerg Exp $

--- locator.cc.orig	2001-07-29 11:33:02.000000000 +0000
+++ locator.cc
@@ -3,15 +3,17 @@
 /* Last change 29.07.2001  */
 
 /* A few includes */
-#include <iostream.h>
+#include <iostream>
 #include <string.h>
 #include <stdio.h>
 
+using namespace std;
+
 /* A few definitions */
 #define VERSION "0.1"
 
 /* Main program */
-main(int argc, char *argv[]) {
+int main(int argc, char *argv[]) {
   float c_long, c_lat;
   char  *locator;
 
