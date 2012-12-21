$NetBSD: patch-doctype_anzlic.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/anzlic.cxx~	2000-02-04 22:49:32.000000000 +0000
+++ doctype/anzlic.cxx
@@ -116,12 +116,12 @@ Original:	Edward C. Zimmermann, edz@bsn.
 Copyright:	A/WWW Enterprises, MCNC/CNIDR and USGS/ANZLIC
 @@@-*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <ctype.h>
-#include <string.h>
-#include <errno.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cctype>
+#include <cstring>
+#include <cerrno>
 
 #include "isearch.hxx"
 #include "sgmlnorm.hxx"
@@ -136,11 +136,11 @@ void ANZLIC::LoadFieldTable() {
   StrList.GetValue("FIELDTYPE", &FieldTypeFilename);
 
   if (FieldTypeFilename.GetLength() == 0) {
-    cout << "No fieldtype file specified.  Assuming all fields are text.";
-    cout << endl;
-    cout << "Make sure you use the correct doctype option:" << endl;
-    cout << endl;
-    cout << "    -o fieldtype=<filename>" << endl;
+    std::cout << "No fieldtype file specified.  Assuming all fields are text.";
+    std::cout << std::endl;
+    std::cout << "Make sure you use the correct doctype option:" << std::endl;
+    std::cout << std::endl;
+    std::cout << "    -o fieldtype=<filename>" << std::endl;
     return;
   }
 
@@ -151,11 +151,11 @@ void ANZLIC::LoadFieldTable() {
 
   // Let's bring the entire file into memory
   if (!fp) {
-    cout << "Specified fieldtype file not found.  Assuming all fields are text.";
-    cout << endl;
-    cout << "Make sure you use the correct doctype option:" << endl;
-    cout << endl;
-    cout << "    -o fieldtype=<filename>" << endl;
+    std::cout << "Specified fieldtype file not found.  Assuming all fields are text.";
+    std::cout << std::endl;
+    std::cout << "Make sure you use the correct doctype option:" << std::endl;
+    std::cout << std::endl;
+    std::cout << "    -o fieldtype=<filename>" << std::endl;
     return;
   }
   fseek(fp, 0L, SEEK_END);
@@ -246,7 +246,7 @@ DOUBLE ANZLIC::ParseDateSingle(const PCH
   else if (Hold.IsNumber())
     fVal = Hold.GetFloat();
   else {
-    cout << "Bad date, value=" << Buffer << endl;
+    std::cout << "Bad date, value=" << Buffer << std::endl;
     fVal = -1.0;
   }
   return fVal;
@@ -276,7 +276,7 @@ void ANZLIC::ParseDateRange(const PCHR B
   } else if (Hold.IsNumber()) {
     *fStart = Hold.GetFloat();
   } else {
-    cout << "Bad Start date, value=" << Buffer << endl;
+    std::cout << "Bad Start date, value=" << Buffer << std::endl;
     *fStart = -1.0;
   }
 
@@ -294,7 +294,7 @@ void ANZLIC::ParseDateRange(const PCHR B
   } else if (Hold.IsNumber()) {
     *fEnd = Hold.GetFloat();
   } else {
-    cout << "Bad End Date, value=" << Buffer << endl;
+    std::cout << "Bad End Date, value=" << Buffer << std::endl;
     *fEnd = 99999999;
   }
 
@@ -344,7 +344,7 @@ void ANZLIC::ParseFields (PRECORD NewRec
 
   PCHR *tags = parse_tags (RecBuffer, ActualLength);
   if (tags == NULL) {
-    cout << "Unable to parse `" << doctype << "' tags in file " << fn << "\n";
+    std::cout << "Unable to parse `" << doctype << "' tags in file " << fn << "\n";
     // Clean up
     delete [] RecBuffer;
     return;
@@ -382,14 +382,14 @@ void ANZLIC::ParseFields (PRECORD NewRec
 	pTmp = (PAMD_Element)Nested.Top();
 	if (Tag == pTmp->get_tag()) {
 	  pTmp = (PAMD_Element)Nested.Pop();
-//	  cout << "Popped " << pTmp->get_tag() << " off the stack.  ";
+//	  std::cout << "Popped " << pTmp->get_tag() << " off the stack.  ";
 	  delete pTmp;
 	  if (Nested.GetSize() != 0) {
 	    pTmp = (PAMD_Element)Nested.Top();
-//	    cout << "Still inside " << pTmp->get_tag() << ".\n";
+//	    std::cout << "Still inside " << pTmp->get_tag() << ".\n";
 	    x = FullFieldname.SearchReverse('_');
 	    FullFieldname.EraseAfter(x-1);
-//	    cout << "Full fieldname is now " << FullFieldname << ".\n";
+//	    std::cout << "Full fieldname is now " << FullFieldname << ".\n";
 	  }
 	}
       } else
@@ -429,14 +429,14 @@ void ANZLIC::ParseFields (PRECORD NewRec
 	  }
 	}
 
-	PCHR unified_name = UnifiedName(*tags_ptr);
+	PKCHR unified_name = UnifiedName(*tags_ptr);
 	// Ignore "unclassified" fields
 	if (unified_name == NULL) 
 	  continue; // ignore these
 	FieldName = unified_name;
 	if (!(FieldName.IsPrint())) {
 	  FieldName.MakePrintable();
-	  cout << "Non-ascii characters found in " << FieldName << endl;
+	  std::cout << "Non-ascii characters found in " << FieldName << std::endl;
 	}
 
 	if (FieldName == "custom")
@@ -464,7 +464,7 @@ void ANZLIC::ParseFields (PRECORD NewRec
 	  FullFieldname.Cat(FieldName);
 	  if (!(FullFieldname.IsPrint())) {
 	    FullFieldname.MakePrintable();
-	    cout << "Non-ascii characters found in " << FullFieldname << endl;
+	    std::cout << "Non-ascii characters found in " << FullFieldname << std::endl;
 	  }
 
 	  STRING FieldType;
@@ -500,8 +500,8 @@ void ANZLIC::ParseFields (PRECORD NewRec
 
 	    dfd_full.SetFieldName (FullFieldname);
 	    dfd_full.SetFieldType (FieldType);
-//	    cout << "Found " << FullFieldname << " of type " << FieldType
-//	      << endl;
+//	    std::cout << "Found " << FullFieldname << " of type " << FieldType
+//	      << std::endl;
 	    Db->DfdtAddEntry (dfd_full);
 	    fc_full.SetFieldStart (val_start);
 	    fc_full.SetFieldEnd (val_end);
@@ -522,7 +522,7 @@ void ANZLIC::ParseFields (PRECORD NewRec
     } else if (p == NULL) {
 #if 1
       // Give some information
-      cout << doctype << " Warning: \""
+      std::cout << doctype << " Warning: \""
 	<< fn << "\" offset " << (*tags_ptr - RecBuffer) << ": "
 	  << "No end tag for <" << *tags_ptr << "> found, skipping field.\n";
 #endif
@@ -840,7 +840,7 @@ ANZLIC::Present (const RESULT& ResultRec
 	    b.ReadFile(FullFilename);
 
 	  } else {
-            cout << "Error: presentation file not found." << endl;
+            std::cout << "Error: presentation file not found." << std::endl;
 	  }
 	}
       }
