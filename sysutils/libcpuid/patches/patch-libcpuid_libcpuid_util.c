$NetBSD: patch-libcpuid_libcpuid_util.c,v 1.1 2022/04/12 22:22:26 nikita Exp $

Upstream commit 1acaf9980b55ae180cc08db218b9face28202519
from Alyssa Ross.

Use popcount64 from libc when available

Without this, we get a compiler error on NetBSD because the one in
libc has a slightly different prototype.

libcpuid_util.c:78:12: error: conflicting types for 'popcount64'
   78 | static int popcount64(uint64_t mask)
      |            ^~~~~~~~~~
In file included from /nix/store/155rj8nqh3xd80vpa8hl35p3hk7pacys-include-netbsd-8.0/include/string.h:98,
                 from libcpuid_util.c:30:
/nix/store/155rj8nqh3xd80vpa8hl35p3hk7pacys-include-netbsd-8.0/include/strings.h:61:14: note: previous declaration of 'popcount64' was here
   61 | unsigned int popcount64(__uint64_t) __constfunc;
      |              ^~~~~~~~~~

* Return unsigned int from popcount64

Matches NetBSD libc, where popcount64 originates.

--- libcpuid/libcpuid_util.c.orig
+++ libcpuid/libcpuid_util.c
@@ -29,6 +29,9 @@
 #include <stdarg.h>
 #include <string.h>
 #include <ctype.h>
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 #include "libcpuid.h"
 #include "libcpuid_util.h"
 
@@ -74,9 +77,10 @@ void debugf(int verboselevel, const char* format, ...)
 	_warn_fun(buff);
 }
 
-static int popcount64(uint64_t mask)
+#ifndef HAVE_POPCOUNT64
+static unsigned int popcount64(uint64_t mask)
 {
-	int num_set_bits = 0;
+	unsigned int num_set_bits = 0;
 
 	while (mask) {
 		mask &= mask - 1;
@@ -85,6 +89,7 @@ static int popcount64(uint64_t mask)
 
 	return num_set_bits;
 }
+#endif
 
 static int score(const struct match_entry_t* entry, const struct cpu_id_t* data,
                  int brand_code, uint64_t bits, int model_code)
