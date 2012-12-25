$NetBSD: patch-src_nlist.cxx,v 1.2 2012/12/25 18:50:18 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification

Also, declare main's return type.

--- src/nlist.cxx.orig	2000-02-04 23:39:56.000000000 +0000
+++ src/nlist.cxx
@@ -44,11 +44,13 @@ Description:	Class NUMERICLIST
 Author:		Jim Fullton, Jim.Fullton@cnidr.org
 @@@*/
 
-#include <stdlib.h>
-#include <iostream.h>
+#include <cstdlib>
+#include <iostream>
 
 #include "nlist.hxx"
 
+using namespace std;
+
 static INT 
 SortCmp(const void* x, const void* y);
 
@@ -875,6 +877,7 @@ NUMERICLIST::TempLoad()
 }
 
 
+int
 main()
 {
   NUMERICLIST list;
