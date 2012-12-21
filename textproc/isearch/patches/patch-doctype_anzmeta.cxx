$NetBSD: patch-doctype_anzmeta.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification
   - string constants are const char *

Fix insecure use of tempnam().

--- doctype/anzmeta.cxx~	2000-10-11 14:02:15.000000000 +0000
+++ doctype/anzmeta.cxx
@@ -124,19 +124,21 @@ Original:	Edward C. Zimmermann, edz@bsn.
 Copyright:	A/WWW Enterprises, MCNC/CNIDR and USGS/FGDC
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
 #include "anzmeta.hxx"
 
+using namespace std;
+
 // IG 19980205 - replaced all MD_Element with ZMD_Element
 //
 // Record Syntaxes are now defined in Isearch/src/defs.cxx
@@ -944,7 +946,7 @@ ANZMETA::ParseFields (RECORD *NewRecord)
 	  }
 	}
 
-	CHR *unified_name = UnifiedName(*tags_ptr);
+	const CHR *unified_name = UnifiedName(*tags_ptr);
 	// Ignore "unclassified" fields
 	if (unified_name == NULL) 
 	  continue; // ignore these
@@ -1446,9 +1448,21 @@ ANZMETA::Present (const RESULT& ResultRe
 	    } else {
 	      STRING s_cmd;
 	      //CHR* c_cmd;
-	      CHR *TmpName;
+	      CHR TmpName[64];
+	      int fd;
 
-	      TmpName = tempnam("/tmp", "mpout");
+	      strcpy(TmpName, "/tmp/mpoutXXXXXX");
+	      fd = mkstemp(TmpName);
+	      if (fd < 0) {
+		 /*
+		  * Apparently failure is not an option here, so
+		  * proceed in a way that at least won't be insecure.
+		  */
+		 strcpy(TmpName, "/dev/null");
+	      }
+	      else {
+		 close(fd);
+	      }
 
           cout << "[ANZMETA::Present] no docs found, so build Fly cmd" << endl;
 
