$NetBSD: patch-doctype_maildigest.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- doctype/maildigest.cxx~	1996-12-21 00:40:39.000000000 +0000
+++ doctype/maildigest.cxx
@@ -113,12 +113,12 @@ Description:	Class MAILDIGEST - Internet
 Author:		Edward C. Zimmermann, edz@bsn.com
 @@@-*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <errno.h>
-#include <ctype.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
+#include <cctype>
 #include "isearch.hxx"
 #include "maildigest.hxx"
 
@@ -141,7 +141,7 @@ void MAILDIGEST::ParseRecords (const REC
   PFILE Fp = fopen (Fn, "rb");
   if (!Fp)
     {
-      cout << "Could not access '" << Fn << "'\n";
+      std::cout << "Could not access '" << Fn << "'\n";
       return;			// File not accessed
 
     }
