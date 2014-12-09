$NetBSD: patch-dbeacon__posix.cpp,v 1.1 2014/12/09 10:45:51 he Exp $

Retry if times() returns with an error.
It has been known to return ((uint32_t)-1).

--- dbeacon_posix.cpp.orig	2007-06-09 11:35:57.000000000 +0000
+++ dbeacon_posix.cpp
@@ -25,6 +25,7 @@
 #include <sys/time.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <syslog.h>
 #include <sys/uio.h>
 #include <sys/times.h>
 
@@ -516,10 +517,19 @@ void address::set(const sockaddr *sa) {
 
 uint64_t get_timestamp() {
 	struct tms tmp;
+	clock_t clk;
+	int n = 0;
 
-	uint64_t v = times(&tmp);
-
-	return (v * 1000) / sysconf(_SC_CLK_TCK);
+    retry:
+	clk = times(&tmp);
+	if (errno != 0) {
+		log(LOG_WARNING, "times() failed: %m");
+		if (++n < 5)
+			goto retry;
+		else
+			log(LOG_ERR, "times() failed after 5 retries: %m");
+	}
+	return (clk * 1000) / sysconf(_SC_CLK_TCK);
 }
 
 uint64_t get_time_of_day() {
