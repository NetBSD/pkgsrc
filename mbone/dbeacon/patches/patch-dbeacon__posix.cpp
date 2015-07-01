$NetBSD: patch-dbeacon__posix.cpp,v 1.3 2015/07/01 09:22:20 he Exp $

Replace use of times() with clock_gettime(CLOCK_MONOTONIC), since
all we use it for is to get a millisecond timestamp, and with a
32-bit unsigned clock_t and 100Hz tick, times() wraps around every
500 days or so, and the code then falls into an assert() in
dbeacon.cpp.

Still retry a few times if clock_gettime() for some reason should
decide to fail.

--- dbeacon_posix.cpp.orig	2007-06-09 11:35:57.000000000 +0000
+++ dbeacon_posix.cpp
@@ -23,8 +23,10 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/time.h>
+#include <time.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <syslog.h>
 #include <sys/uio.h>
 #include <sys/times.h>
 
@@ -515,11 +517,24 @@ void address::set(const sockaddr *sa) {
 }
 
 uint64_t get_timestamp() {
-	struct tms tmp;
+	struct timespec ts;
+	uint64_t timestamp;
+	int n = 0;
 
-	uint64_t v = times(&tmp);
+    retry:
+	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
+		log(LOG_WARNING, "clock_gettime(CLOCK_MONOTONIC) failed: %m");
+		if (++n < 5)
+			goto retry;
+		else
+			log(LOG_ERR,
+			    "clock_gettime(CLOCK_MONOTONIC) failed after 5 retries: %m");
+	}
+	timestamp = ts.tv_sec;
+	timestamp *= 1000;
+	timestamp += ts.tv_nsec / 1000000;
 
-	return (v * 1000) / sysconf(_SC_CLK_TCK);
+	return timestamp;
 }
 
 uint64_t get_time_of_day() {
