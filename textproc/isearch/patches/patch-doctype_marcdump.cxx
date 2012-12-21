$NetBSD: patch-doctype_marcdump.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification
   - string constants are const char *

--- doctype/marcdump.cxx~	1998-12-01 14:59:04.000000000 +0000
+++ doctype/marcdump.cxx
@@ -7,12 +7,12 @@ Author:		Archibald Warnock (warnock@clar
 Copyright:	A/WWW Enterprises, Columbia, MD
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
 #include "opobj.hxx"
 #include "operand.hxx"
@@ -27,6 +27,8 @@ Copyright:	A/WWW Enterprises, Columbia, 
 
 #include "marcdump.hxx"
 
+using namespace std;
+
 // Local prototypes
 static CHR **parse_tags (CHR *b, GPTYPE len);
 int          usefulMarcDumpField(char *fieldStr);
@@ -243,7 +245,7 @@ MARCDUMP::ParseFields (RECORD *NewRecord
       val_len--;
     if (val_len <= 0) continue; // Don't bother with empty fields (J. Mandel)
     
-    CHR* unified_name = UnifiedName(tag);
+    const CHR* unified_name = UnifiedName(tag);
 
     // Ignore "unclassified" fields
     if (unified_name == NULL) 
@@ -288,8 +290,8 @@ MARCDUMP::ParseFields (RECORD *NewRecord
 }
 
 
-CHR*
-MARCDUMP::UnifiedName (CHR *tag)
+const CHR*
+MARCDUMP::UnifiedName (const CHR *tag)
 {
   return tag; // Identity
 }
