$NetBSD: patch-src_qso__db.h,v 1.2 2012/11/16 00:33:36 gdt Exp $

--- src/qso_db.h.orig	2005-09-02 10:18:51.000000000 +0000
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
