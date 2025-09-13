$NetBSD: patch-main.c,v 1.3 2025/09/13 16:19:20 vins Exp $

* Provide an implementation of recallocarray().

--- main.c.orig	2025-05-19 19:01:24.000000000 +0000
+++ main.c
@@ -1,5 +1,6 @@
 /*
  * Copyright (c) 2019 Martijn van Duren <martijn@openbsd.org>
+ * Copyright (c) 2012 Eric Faurot <eric@openbsd.org>
  *
  * Permission to use, copy, modify, and distribute this software for any
  * purpose with or without fee is hereby granted, provided that the above
@@ -30,6 +31,42 @@
 #include <asr.h>
 
 #include "opensmtpd.h"
+#include "compat.h"
+
+void *recallocarray(void *ptr, size_t om, size_t m, size_t n)
+{
+	void *newptr;
+	size_t old_size, new_size;
+
+	if (n && m > -1 / n) {
+		errno = ENOMEM;
+		return 0;
+	}
+	new_size = m * n;
+
+	if (n && om > -1 / n) {
+		errno = EINVAL;
+		return 0;
+	}
+	old_size = om * n;
+
+	newptr = calloc(m, n);
+	if (!newptr)
+		return ptr;
+
+	if (new_size <= old_size) {
+		memcpy((char *) newptr, ptr, new_size);
+	}
+	else {
+		memcpy((char *) newptr, ptr, old_size);
+		memset((char *) newptr + old_size, 0, new_size - old_size);
+	}
+
+	memset(ptr, 0, old_size);
+	free(ptr);
+
+	return newptr;
+}
 
 struct dnsbl_session;
 
