$NetBSD: patch-src_intlist.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification

--- src/intlist.cxx~	2000-10-15 03:46:31.000000000 +0000
+++ src/intlist.cxx
@@ -45,12 +45,14 @@ Author:		Archie Warnock (warnock@clark.n
                 Derived from class NLIST by J. Fullton
 @@@*/
 
-#include <stdlib.h>
-#include <time.h>
-#include <iostream.h>
+#include <cstdlib>
+#include <ctime>
+#include <iostream>
 
 #include "intlist.hxx"
 
+using namespace std;
+
 // Prototypes
 static INT 
 SortStartCmp(const void* x, const void* y);
