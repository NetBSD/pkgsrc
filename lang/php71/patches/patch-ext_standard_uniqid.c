$NetBSD: patch-ext_standard_uniqid.c,v 1.2 2017/07/19 02:44:45 manu Exp $

PHP uniqid() relies on microsecond-precise system clock to produce an
unique identifier. In order to avoid  using the same value, it first
calls usleep(1) to wait for the next microsecond. 

Unfortunately, usleep() specification says "The suspension time may be 
longer than requested due to the scheduling of other activity by the 
system." Indeed, the pause may as as long as an entire execution slice, 
causing a uniqid() call to last more than 10 ms.

This is fixed by replacing the usleep() call by time polling using
gettimeofday() until the microscecond change. Since the getttimeoday()
system call lasts around a microsecond, only a small time is wasted
calling  multiple gettimeofday. On the benefit side, uniqid() performance
in increased 10000 fold without changing its behavior.

Submitted upstream as https://bugs.php.net/bug.php?id=74851

--- ext/standard/uniqid.c.orig	2017-06-07 10:09:31.000000000 +0200
+++ ext/standard/uniqid.c	2017-07-08 08:24:24.000000000 +0200
@@ -52,25 +52,31 @@
 	zend_string *uniqid;
 	int sec, usec;
 	size_t prefix_len = 0;
 	struct timeval tv;
+	ZEND_TLS struct timeval prev_tv = { 0, 0 };
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|sb", &prefix, &prefix_len,
 							  &more_entropy)) {
 		return;
 	}
 
-#if HAVE_USLEEP && !defined(PHP_WIN32)
 	if (!more_entropy) {
-#if defined(__CYGWIN__)
-		php_error_docref(NULL, E_WARNING, "You must use 'more entropy' under CYGWIN");
-		RETURN_FALSE;
-#else
-		usleep(1);
-#endif
+		/* This implementation needs current microsecond to change,
+		 * hence we poll time until it does. This is much faster than
+		 * calling usleep(1) which may cause the kernel to schedule
+		 * another process, causing a pause of around 10ms. 
+		 */
+		do {
+			(void)gettimeofday((struct timeval *) &tv,
+					   (struct timezone *) NULL);
+		} while (tv.tv_sec == prev_tv.tv_sec && 
+			 tv.tv_usec == prev_tv.tv_usec); 
+
+		prev_tv.tv_sec = tv.tv_sec;
+		prev_tv.tv_usec = tv.tv_usec;
 	}
-#endif
-	gettimeofday((struct timeval *) &tv, (struct timezone *) NULL);
+
 	sec = (int) tv.tv_sec;
 	usec = (int) (tv.tv_usec % 0x100000);
 
 	/* The max value usec can have is 0xF423F, so we use only five hex
