$NetBSD: patch-programs_frametest.c,v 1.2 2014/12/12 11:20:56 fhajny Exp $

--- programs/frametest.c.orig	2014-11-06 18:39:42.000000000 +0000
+++ programs/frametest.c
@@ -42,7 +42,7 @@
 **************************************/
 #include <stdlib.h>
 #include <stdio.h>      // fgets, sscanf
-#include <sys/timeb.h>  // timeb
+#include <sys/time.h>  // timeb
 #include <string.h>     // strcmp
 #include "lz4frame.h"
 #include "xxhash.h"     // XXH64
@@ -113,11 +113,9 @@ static U32 pause = 0;
 *********************************************************/
 static U32 FUZ_GetMilliStart(void)
 {
-    struct timeb tb;
-    U32 nCount;
-    ftime( &tb );
-    nCount = (U32) (((tb.time & 0xFFFFF) * 1000) +  tb.millitm);
-    return nCount;
+    struct timeval tv;
+    gettimeofday(&tv, NULL);
+    return (tv.tv_usec/1000 + (tv.tv_sec & 0xfffff) * 1000);
 }
 
 
