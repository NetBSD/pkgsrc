$NetBSD: patch-src_fcstat.c,v 1.7 2025/03/30 21:10:42 wiz Exp $

The argument types to scandir(3) differ between different OSes.
I used the provided alphasort instead of rewriting the equivalent
sorter function.

--- src/fcstat.c.orig	2016-04-06 03:22:55.000000000 +0000
+++ src/fcstat.c
@@ -52,6 +52,9 @@ typedef long long INT64;
 #define EPOCH_OFFSET 11644473600i64
 typedef __int64 INT64;
 #endif
+#if defined(_SCO_DS)
+#include "../scandir.c"
+#endif
 
 /* Workaround for problems in the stat() in the Microsoft C library:
  *
