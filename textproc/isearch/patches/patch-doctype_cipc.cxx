$NetBSD: patch-doctype_cipc.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification
   - string constants are const char *

--- doctype/cipc.cxx~	2000-06-16 00:53:06.000000000 +0000
+++ doctype/cipc.cxx
@@ -118,19 +118,21 @@ Original:	Edward C. Zimmermann, edz@bsn.
 Copyright:	A/WWW Enterprises, MCNC/CNIDR and NASA
 @@@-*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <ctype.h>
-#include <string.h>
-#include <errno.h>
-#include <math.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cctype>
+#include <cstring>
+#include <cerrno>
+#include <cmath>
 
 #include "isearch.hxx"
 #include "date.hxx"
 #include "sgmlnorm.hxx"
 #include "cipc.hxx"
 
+using namespace std;
+
 extern DOUBLE GetNumericValue(const CHR* Buffer, const CHR* Tag, const CHR* eTag);
 
 /* ------- CIPC Support --------------------------------------------- */
@@ -970,7 +972,7 @@ CIPC::ParseFields (RECORD *NewRecord)
 	  }
 	}
 
-	CHR *unified_name = UnifiedName(*tags_ptr);
+	const CHR *unified_name = UnifiedName(*tags_ptr);
 	// Ignore "unclassified" fields
 	if (unified_name == NULL) 
 	  continue; // ignore these
