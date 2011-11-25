$NetBSD: patch-src_qso__db.h,v 1.1 2011/11/25 21:59:57 joerg Exp $

--- src/qso_db.h.orig	2011-11-25 17:49:53.000000000 +0000
+++ src/qso_db.h
@@ -1,8 +1,8 @@
 #ifndef QSO_DB
 #define QSO_DB
 
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 //#include <istream>
 //#include <ostream>
 //#include <fstream>
@@ -12,6 +12,8 @@
 
 #include "adif_def.h"
 //#include "myprofile.h"
+
+using namespace std;
 
 #ifndef TRUE
 #define TRUE 1
