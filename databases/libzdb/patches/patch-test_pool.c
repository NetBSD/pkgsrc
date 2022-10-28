$NetBSD: patch-test_pool.c,v 1.1 2022/10/28 18:06:09 he Exp $

Fix handling of time_t on NetBSD.

--- test/pool.c.orig	2019-04-30 14:11:41.000000000 +0000
+++ test/pool.c
@@ -5,6 +5,7 @@
 #include <assert.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <inttypes.h>
 
 #include "URL.h"
 #include "Thread.h"
@@ -684,7 +685,11 @@ static void testPool(const char *testURL
                         assert(timestampAsTm.tm_sec == 58);
                         assert(timestampAsTm.TM_GMTOFF == 0);
                         // Result
+#if defined(__NetBSD__)
+                        printf("\tDate: %s, Time: %s, DateTime: %s\n\tTimestamp as numeric: %" PRId64 ", Timestamp as string: %s\n",
+#else
                         printf("\tDate: %s, Time: %s, DateTime: %s\n\tTimestamp as numeric: %ld, Timestamp as string: %s\n",
+#endif
                                ResultSet_getString(r, 1),
                                ResultSet_getString(r, 2),
                                ResultSet_getString(r, 3),
