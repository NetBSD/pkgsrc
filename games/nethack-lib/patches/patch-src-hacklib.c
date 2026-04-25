$NetBSD: patch-src-hacklib.c,v 1.1 2026/04/25 07:12:01 mrg Exp $

Use LOCALTIME_type for localtime() to avoid failing on powerpc.

--- src/hacklib.c.orig	2023-02-15 21:52:57.000000000 +0000
+++ src/hacklib.c	2026-02-01 22:02:20.288529244 +0000
@@ -1016,12 +1016,7 @@ time_t date;
     if (date == 0)
         lt = getlt();
     else
-#if (defined(ULTRIX) && !(defined(ULTRIX_PROTO) || defined(NHSTDC))) \
-    || defined(BSD)
-        lt = localtime((long *) (&date));
-#else
-        lt = localtime(&date);
-#endif
+        lt = localtime((LOCALTIME_type) (&date));
     /* just in case somebody's localtime supplies (year % 100)
        rather than the expected (year - 1900) */
     if (lt->tm_year < 70)
