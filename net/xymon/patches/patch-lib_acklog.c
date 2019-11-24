$NetBSD: patch-lib_acklog.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- lib/acklog.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/acklog.c
@@ -126,10 +126,14 @@ void do_acklog(FILE *output, int maxcoun
 			/* Show only the first 30 characters in message */
 			if (strlen(ackmsg) > 30) ackmsg[30] = '\0';
 
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 			#pragma GCC diagnostic push
 			#pragma GCC diagnostic ignored "-Wformat-truncation"
+#endif  // __GNUC__
 			snprintf(ackfn, sizeof(ackfn), "%s/ack.%s", xgetenv("XYMONACKDIR"), hosttest);
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 			#pragma GCC diagnostic pop
+#endif  // __GNUC__
 
 			testname = strrchr(hosttest, '.');
 			if (testname) {
