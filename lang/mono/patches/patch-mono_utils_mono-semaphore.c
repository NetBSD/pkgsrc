$NetBSD: patch-mono_utils_mono-semaphore.c,v 1.1 2015/05/21 14:38:08 kefren Exp $

A grotty implementation of sem_timedwait for NetBSD

--- mono/utils/mono-semaphore.c.orig	2015-04-24 04:26:18.000000000 +0300
+++ mono/utils/mono-semaphore.c	2015-05-21 16:19:49.000000000 +0300
@@ -25,6 +25,9 @@
 #  elif defined(__native_client__) && defined(USE_NEWLIB)
 #    define TIMESPEC struct timespec
 #    define WAIT_BLOCK(a, b) sem_trywait(a)
+#  elif defined(__NetBSD__)
+#    define TIMESPEC struct timespec
+#    define WAIT_BLOCK(a, b) netbsd_sem_timedwait(a, b)
 #  else
 #    define TIMESPEC struct timespec
 #    define WAIT_BLOCK(a,b) sem_timedwait (a, b)
@@ -34,6 +37,38 @@
 #define NSEC_PER_SEC 1000000000
 #endif
 
+#if defined(__NetBSD__)
+
+/* XXX: Actually I think NetBSD-current has sem_timedwait */
+int netbsd_sem_timedwait(sem_t *sem, TIMESPEC *tv);
+
+int
+netbsd_sem_timedwait(sem_t *sem, TIMESPEC *tv)
+{
+	struct timeval tval;
+
+	TIMESPEC_TO_TIMEVAL(&tval, tv);
+
+	while(sem_trywait(sem) == -1) {
+		struct timeval t;
+
+		if (errno == EINVAL)
+			return -1;
+
+		usleep(1000);
+		gettimeofday(&t, NULL);
+		if (t.tv_sec > tval.tv_sec ||
+		    (t.tv_sec == tval.tv_sec && t.tv_usec > tval.tv_usec)) {
+			errno = ETIMEDOUT;
+			return -1;
+		}
+	}
+
+	return 0;
+}
+
+#endif
+
 int
 mono_sem_timedwait (MonoSemType *sem, guint32 timeout_ms, gboolean alertable)
 {
