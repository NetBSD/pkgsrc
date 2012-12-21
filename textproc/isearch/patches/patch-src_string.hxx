$NetBSD: patch-src_string.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- src/string.hxx.orig	2000-10-31 06:22:09.000000000 +0000
+++ src/string.hxx
@@ -43,8 +43,9 @@ Author:		Nassib Nassar, nrn@cnidr.org
 #ifndef STRING_HXX
 #define STRING_HXX
 
-#include <string.h>
-#include <iostream.h>
+#include <cstring>
+#include <iostream>
+#include <iomanip>
 #include "gdt.h"
 #include "defs.hxx"
 
@@ -53,7 +54,7 @@ Author:		Nassib Nassar, nrn@cnidr.org
 #include <time.h>
 #endif
 
-extern CHR *transcode (CHR *buffer, char **transarray);
+extern CHR *transcode (CHR *buffer, const char **transarray);
 
 typedef size_t STRINGINDEX;
 typedef STRINGINDEX* PSTRINGINDEX;
@@ -92,8 +93,8 @@ public:
   INT         CaseEquals(const CHR* CString) const;
   void        Print() const;
   void        Print(PFILE FilePointer) const;
-  friend      ostream& operator<<(ostream& os, const STRING& str);
-  friend      istream& operator>>(istream& os, STRING& str);
+  friend      std::ostream& operator<<(std::ostream& os, const STRING& str);
+  friend      std::istream& operator>>(std::istream& os, STRING& str);
   INT         GetInt() const;
   LONG        GetLong() const;
   DOUBLE      GetFloat() const;
