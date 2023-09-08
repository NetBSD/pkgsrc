$NetBSD: patch-compat.h,v 1.1 2023/09/08 21:05:37 vins Exp $

* Provide an inline definition of pledge().
* Provide function prototypes for recallocarray()
  and gethostbyname_async().

--- compat.h.orig	2023-09-08 20:40:55.417811491 +0000
+++ compat.h
@@ -0,0 +1,21 @@
+/*
+ * <unistd.h>
+ */
+
+static inline int
+pledge(const char *promises, const char *execpromises)
+{
+        return 0;
+}
+
+/*
+ * <stdlib.h>
+ */
+
+void *recallocarray (void *, size_t, size_t, size_t);
+
+/*
+ * <asr.h>
+ */
+
+struct asr_query *gethostbyname_async(const char *, void *);
