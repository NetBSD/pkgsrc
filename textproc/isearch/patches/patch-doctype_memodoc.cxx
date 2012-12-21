$NetBSD: patch-doctype_memodoc.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- doctype/memodoc.cxx~	1998-05-12 16:48:34.000000000 +0000
+++ doctype/memodoc.cxx
@@ -113,12 +113,12 @@ Description:	Class MEMODOC - Colon-like 
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
 #include "memodoc.hxx"
 
@@ -174,11 +174,11 @@ void MEMODOC::ParseFields (PRECORD NewRe
       if (tags)
 	{
 	  delete tags;
-	  cout << "Warning: No `" << doctype << "' fields/tags in \"" << fn << "\" record.\n";
+	  std::cout << "Warning: No `" << doctype << "' fields/tags in \"" << fn << "\" record.\n";
 	}
        else
 	{
-	  cout << "Unable to parse `" << doctype << "' record in \"" << fn << "\".\n";
+	  std::cout << "Unable to parse `" << doctype << "' record in \"" << fn << "\".\n";
 	}
       delete [] RecBuffer;
       return;
