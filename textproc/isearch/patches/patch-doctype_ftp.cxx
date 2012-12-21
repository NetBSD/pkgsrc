$NetBSD: patch-doctype_ftp.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- doctype/ftp.cxx~	1996-12-21 00:40:37.000000000 +0000
+++ doctype/ftp.cxx
@@ -6,7 +6,7 @@ Description: class FTP - index files bas
 Author:      Erik Scott, Scott Technologies, Inc.
 */
 
-#include <ctype.h>
+#include <cctype>
 #include "isearch.hxx"
 #include "ftp.hxx"
 
@@ -27,7 +27,7 @@ STRING myBuff;
 ResultRecord.GetRecordData(&myBuff);
 STRINGINDEX firstNL = myBuff.Search('\n');
 if (firstNL == 0) {
-   cout << "FTP::Present() -- Can't find first Newline in file to present.\n";
+   std::cout << "FTP::Present() -- Can't find first Newline in file to present.\n";
    return;
    }
 
