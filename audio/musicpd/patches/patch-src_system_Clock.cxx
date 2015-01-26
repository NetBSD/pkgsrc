$NetBSD: patch-src_system_Clock.cxx,v 1.1 2015/01/26 07:26:55 pho Exp $

Avoid integer overflow in MonotonicClock{S,MS,US}

This is Darwin specific: the original implementation was causing an
integer overflow when base.numer was very large. On PPC Darwin, the
timebase is 1000000000/33330116 and this is too large for integer
arithmetic.

http://bugs.musicpd.org/view.php?id=4292

--- src/system/Clock.cxx.orig	2015-01-26 06:16:36.000000000 +0000
+++ src/system/Clock.cxx
@@ -40,8 +40,8 @@ MonotonicClockS(void)
 	if (base.denom == 0)
 		(void)mach_timebase_info(&base);
 
-	return (unsigned)((mach_absolute_time() * base.numer / 1000)
-			  / (1000000 * base.denom));
+	return (unsigned)(((double)mach_absolute_time() * base.numer / 1000)
+			  / base.denom / 1000000);
 #elif defined(CLOCK_MONOTONIC)
 	struct timespec ts;
 	clock_gettime(CLOCK_MONOTONIC, &ts);
@@ -62,8 +62,8 @@ MonotonicClockMS(void)
 	if (base.denom == 0)
 		(void)mach_timebase_info(&base);
 
-	return (unsigned)((mach_absolute_time() * base.numer)
-			  / (1000000 * base.denom));
+	return (unsigned)(((double)mach_absolute_time() * base.numer)
+			  / base.denom / 1000000);
 #elif defined(CLOCK_MONOTONIC)
 	struct timespec ts;
 	clock_gettime(CLOCK_MONOTONIC, &ts);
@@ -104,8 +104,8 @@ MonotonicClockUS(void)
 	if (base.denom == 0)
 		(void)mach_timebase_info(&base);
 
-	return ((uint64_t)mach_absolute_time() * (uint64_t)base.numer)
-		/ (1000 * (uint64_t)base.denom);
+	return (uint64_t)(((double)mach_absolute_time() * base.numer)
+		/ base.denom / 1000);
 #elif defined(CLOCK_MONOTONIC)
 	struct timespec ts;
 	clock_gettime(CLOCK_MONOTONIC, &ts);
