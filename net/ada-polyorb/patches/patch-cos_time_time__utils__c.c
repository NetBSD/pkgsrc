$NetBSD: patch-cos_time_time__utils__c.c,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

Make C preprocessed symbols on NetBSD to fix link-time warning

--- /dev/null
+++ cos/time/time_utils_c.c
@@ -0,0 +1,7 @@
+#if defined(__NetBSD__)
+#include <time.h>
+time_t __gnat_time (time_t *tloc)
+{
+    return time(tloc)
+}
+#endif
