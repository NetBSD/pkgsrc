$NetBSD: patch-doctype_referbib.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/referbib.cxx~	1998-05-12 16:48:34.000000000 +0000
+++ doctype/referbib.cxx
@@ -113,12 +113,12 @@ Description:	Class REFERBIB - Refer bibl
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
 #include "referbib.hxx"
 
@@ -168,7 +168,7 @@ void REFERBIB::ParseRecords (const RECOR
   PFILE Fp = fopen (Fn, "rb");
   if (!Fp)
     {
-      cout << "Could not access " << Fn << "\n";
+      std::cout << "Could not access " << Fn << "\n";
       return;			// File not accessed
 
     }
@@ -262,7 +262,7 @@ NOTE:
 formats that might be added to Isearch, eg. BibTeX
 */
 
-PCHR REFERBIB::UnifiedName(PCHR tag) const
+PKCHR REFERBIB::UnifiedName(PKCHR tag) const
 {
 #if USE_UNIFIED_NAMES
   const char *Table[] = {
@@ -299,7 +299,7 @@ PCHR REFERBIB::UnifiedName(PCHR tag) con
   // Ignore lower case tags
   if (tag[1] < 'A' || tag[1] > 'Z') return NULL;
   // Return unified field name
-  return (PCHR)Table[(unsigned)tag[1] - (unsigned)'A'];
+  return Table[(unsigned)tag[1] - (unsigned)'A'];
 #else
   return tag; // Identity
 #endif
@@ -341,11 +341,11 @@ void REFERBIB::ParseFields (PRECORD NewR
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
@@ -384,7 +384,7 @@ void REFERBIB::ParseFields (PRECORD NewR
 	}
 #endif
 
-      PCHR unified_name = UnifiedName(*tags_ptr);
+      PKCHR unified_name = UnifiedName(*tags_ptr);
 #if WANT_MISC
       // Throw "unclassified" into Misc
       FieldName = unified_name ? unified_name: "Misc";
