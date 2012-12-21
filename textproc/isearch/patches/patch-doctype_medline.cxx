$NetBSD: patch-doctype_medline.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/medline.cxx~	1998-05-12 16:48:34.000000000 +0000
+++ doctype/medline.cxx
@@ -117,12 +117,12 @@ Copyright:	Basis Systeme netzwerk, Munic
 
 // TODO: Clean-up Record parser and fix to leave off junk between records
 
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
 #include "medline.hxx"
 
@@ -162,7 +162,7 @@ void MEDLINE::ParseRecords (const RECORD
   PFILE Fp = fopen (Fn, "rb");
   if (!Fp)
     {
-      cout << "Could not access " << Fn << "\n";
+      std::cout << "Could not access " << Fn << "\n";
       return;			// File not accessed
 
     }
@@ -269,7 +269,7 @@ void MEDLINE::ParseRecords (const RECORD
  flavours.
 */
 
-PCHR MEDLINE::UnifiedName (PCHR tag) const
+PKCHR MEDLINE::UnifiedName (PKCHR tag) const
 {
 printf("Medline:UnifiedName called\n");
 #if USE_UNIFIED_NAMES
@@ -314,11 +314,11 @@ void MEDLINE::ParseFields (PRECORD NewRe
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
@@ -352,7 +352,7 @@ void MEDLINE::ParseFields (PRECORD NewRe
       //      if (val_len <= 0) continue; // Skip blank fields
       if (val_len < 0) continue; // Skip blank fields
 
-      PCHR unified_name = UnifiedName(*tags_ptr);
+      PKCHR unified_name = UnifiedName(*tags_ptr);
 #if WANT_MISC
       // Throw "unclassified" into Misc
       FieldName = unified_name ? unified_name: "Misc";
