$NetBSD: patch-doctype_sgmlnorm.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/sgmlnorm.cxx~	2000-02-04 22:48:27.000000000 +0000
+++ doctype/sgmlnorm.cxx
@@ -156,9 +156,9 @@ Authors:   	Kevin Gamiel, Kevin.Gamiel@c
 Copyright:	BSn/CNIDR
 @@@-*/
 
-#include <stdlib.h>
-#include <ctype.h>
-#include <string.h>
+#include <cstdlib>
+#include <cctype>
+#include <cstring>
 #include "isearch.hxx"
 //#include "common.hxx"
 //#include "doctype.hxx"
@@ -178,7 +178,7 @@ void SGMLNORM::ParseRecords (const RECOR
 
 
 
-PCHR SGMLNORM::UnifiedName (PCHR tag) const
+PKCHR SGMLNORM::UnifiedName (PKCHR tag) const
 {
   return tag;
 }
@@ -225,7 +225,7 @@ void SGMLNORM::ParseFields (PRECORD NewR
   PCHR *tags = parse_tags (RecBuffer, ActualLength);
   if (tags == NULL)
     {
-      cout << "Unable to parse `" << doctype << "' tags in file " << fn << "\n";
+      std::cout << "Unable to parse `" << doctype << "' tags in file " << fn << "\n";
       // Clean up
       delete[]RecBuffer;
       return;
@@ -284,7 +284,7 @@ void SGMLNORM::ParseFields (PRECORD NewR
 	      else
 		{
 #endif
-		  PCHR unified_name = UnifiedName(*tags_ptr);
+		  PKCHR unified_name = UnifiedName(*tags_ptr);
 		  // Ignore "unclassified" fields
 		  if (unified_name == NULL) continue; // ignore these
 		  FieldName = unified_name;
@@ -315,7 +315,7 @@ void SGMLNORM::ParseFields (PRECORD NewR
 	{
 #if 1
 	  // Give some information
-	  cout << doctype << " Warning: \""
+	  std::cout << doctype << " Warning: \""
 	    << fn << "\" offset " << (*tags_ptr - RecBuffer) << ": "
 	    << "No end tag for <" << *tags_ptr << "> found, skipping field.\n";
 #endif
