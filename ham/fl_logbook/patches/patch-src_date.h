$NetBSD: patch-src_date.h,v 1.2 2012/11/16 00:33:36 gdt Exp $

--- src/date.h.orig	2006-09-11 15:40:15.000000000 +0000
+++ src/date.h
@@ -25,13 +25,15 @@
 #ifndef DATE_H
 #define DATE_H
 
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
+using namespace std;
+
 typedef enum {
   SUNDAY,
   MONDAY,
