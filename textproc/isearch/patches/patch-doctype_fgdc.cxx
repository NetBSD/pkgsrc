$NetBSD: patch-doctype_fgdc.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification
   - string constants are const char *

Fix insecure use of tempnam().

--- doctype/fgdc.cxx~	2000-09-06 18:20:30.000000000 +0000
+++ doctype/fgdc.cxx
@@ -120,19 +120,21 @@ Original:	Edward C. Zimmermann, edz@bsn.
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
 #include "fgdc.hxx"
 
+using namespace std;
+
 #define PRESENT_PROGRAM "/home/cnidr/bin/mp -c /home/cnidr/bin/deluxe.cfg"
 
 void BuildCommandLine(const STRING& Command, const STRING& FullFilename, 
@@ -966,7 +968,7 @@ FGDC::ParseFields (RECORD *NewRecord)
 	  }
 	}
 
-	CHR *unified_name = UnifiedName(*tags_ptr);
+	const CHR *unified_name = UnifiedName(*tags_ptr);
 	// Ignore "unclassified" fields
 	if (unified_name == NULL) 
 	  continue; // ignore these
@@ -1824,10 +1826,22 @@ FGDC::Present (const RESULT& ResultRecor
 	      return;
 	    } else {
 	      STRING s_cmd;
-	      CHR *TmpName;
-
-	      TmpName = tempnam("/tmp", "mpout");
+	      CHR TmpName[64];
+	      int fd;
 
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
+	      
 	      BuildCommandLine(mpCommand, HoldFilename, RecordSyntax, 
 			       TmpName, &s_cmd);
 	      system(s_cmd);
