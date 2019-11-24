$NetBSD: patch-lib_timefunc.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- lib/timefunc.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/timefunc.c
@@ -393,10 +393,14 @@ char *histlogtime(time_t histtime)
 	if (d2[0] == '0') { d2[0] = d2[1]; d2[1] = '\0'; }
         strftime(d3, sizeof(d3), "_%H:%M:%S_%Y", localtime(&histtime));
 
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 	#pragma GCC diagnostic push
 	#pragma GCC diagnostic ignored "-Wformat-truncation"
+#endif  // __GNUC__
 	snprintf(result, result_buflen, "%s%s%s", d1, d2, d3);
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 	#pragma GCC diagnostic pop
+#endif  // __GNUC__
 
 	MEMUNDEFINE(d1); MEMUNDEFINE(d2); MEMUNDEFINE(d3);
 
