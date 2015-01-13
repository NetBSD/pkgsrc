$NetBSD: patch-dbeacon__posix.cpp,v 1.2 2015/01/13 20:25:13 he Exp $

Replace use of times() with gettimeofday(), since all we use it
for is to get a millisecond timestamp, and with a 32-bit unsigned
clock_t and 100Hz tick, times() wraps around every 500 days or so,
and the code then falls into an assert() in dbeacon.cpp.

Still retry a few times if gettimeofday() for some reason should
decide to fail.

--- dbeacon_posix.cpp.orig	2007-06-09 11:35:57.000000000 +0000
+++ dbeacon_posix.cpp
@@ -25,6 +25,7 @@
 #include <sys/time.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <syslog.h>
 #include <sys/uio.h>
 #include <sys/times.h>
 
@@ -515,11 +516,24 @@ void address::set(const sockaddr *sa) {
 }
 
 uint64_t get_timestamp() {
-	struct tms tmp;
+	struct timeval tv;
+	uint64_t timestamp;
+	int n = 0;
 
-	uint64_t v = times(&tmp);
+    retry:
+	if (gettimeofday(&tv, 0) != 0) {
+		log(LOG_WARNING, "gettimeofday() failed: %m");
+		if (++n < 5)
+			goto retry;
+		else
+			log(LOG_ERR,
+			    "gettimeofday() failed after 5 retries: %m");
+	}
+	timestamp = tv.tv_sec;
+	timestamp *= 1000;
+	timestamp += tv.tv_usec / 1000;
 
-	return (v * 1000) / sysconf(_SC_CLK_TCK);
+	return timestamp;
 }
 
 uint64_t get_time_of_day() {
