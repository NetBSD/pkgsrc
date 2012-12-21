$NetBSD: patch-doctype_colondoc.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/colondoc.cxx~	1998-05-12 16:48:28.000000000 +0000
+++ doctype/colondoc.cxx
@@ -116,12 +116,12 @@ Author:		Edward C. Zimmermann, edz@bsn.c
 Distribution:   Isite modifications by A. Warnock (warnock@clark.net)
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
 #include "colondoc.hxx"
 
@@ -147,7 +147,7 @@ void COLONDOC::ParseRecords (const RECOR
 }
 
 
-PCHR COLONDOC::UnifiedName (PCHR tag) const
+PKCHR COLONDOC::UnifiedName (PKCHR tag) const
 {
   return tag; // Identity
 }
@@ -185,11 +185,11 @@ void COLONDOC::ParseFields (PRECORD NewR
       if (tags)
 	{
 	  delete tags;
-	  cout << "Warning: No `" << doctype << "' fields/tags in \"" << fn << "\"\n";
+	  std::cout << "Warning: No `" << doctype << "' fields/tags in \"" << fn << "\"\n";
 	}
       else
 	{
-	  cout << "Unable to parse `" << doctype << "' record in \"" << fn << "\"\n";
+	  std::cout << "Unable to parse `" << doctype << "' record in \"" << fn << "\"\n";
 	}
       delete [] RecBuffer;
       return;
@@ -221,7 +221,7 @@ void COLONDOC::ParseFields (PRECORD NewR
       if (val_len < 0) continue; // Don't bother with empty fields (J. Mandel)
       //      if (val_len <= 0) continue; // Don't bother with empty fields
 
-      PCHR unified_name = UnifiedName(*tags_ptr);
+      PKCHR unified_name = UnifiedName(*tags_ptr);
 #if WANT_MISC
       // Throw "unclassified" into Misc
       FieldName = unified_name ? unified_name: "Misc";
