$NetBSD: patch-src_Iindex.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers

Use the correct type to convert pointers to integers.

--- src/Iindex.cxx~	2000-10-26 00:56:35.000000000 +0000
+++ src/Iindex.cxx
@@ -42,11 +42,12 @@ Description:	Command-line indexer
 Author:		Nassib Nassar, nrn@cnidr.org
 @@@*/
 
-#include <stdlib.h>
-#include <errno.h>
-#include <string.h>
-#include <locale.h>
-#include <time.h>
+#include <cstdlib>
+#include <cerrno>
+#include <cstring>
+#include <clocale>
+#include <ctime>
+#include <stdint.h>
 
 #if defined(_MSDOS) || defined(_WIN32)
 #include <direct.h>
@@ -170,7 +171,7 @@ AddFile(PIDB IdbPtr, STRING& PathName, S
 	}
       }
       if (Found) {
-	Offset = (GPTYPE)((UINT4)Found - (UINT4)Buffer);
+	Offset = (GPTYPE)((uintptr_t)Found - (uintptr_t)Buffer);
 	/* the separator marks the beginning of the next 
 	   record. (offset - 1), then marks the end of 
 	   the current record. we must make sure that the
