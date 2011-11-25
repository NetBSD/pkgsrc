$NetBSD: patch-src_date.h,v 1.1 2011/11/25 21:59:57 joerg Exp $

--- src/date.h.orig	2011-11-25 17:49:57.000000000 +0000
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
