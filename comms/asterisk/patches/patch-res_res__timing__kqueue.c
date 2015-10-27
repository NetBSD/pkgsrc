$NetBSD: patch-res_res__timing__kqueue.c,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- res/res_timing_kqueue.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ res/res_timing_kqueue.c
@@ -71,9 +71,12 @@ static struct ast_timing_interface kqueu
 static struct ao2_container *kqueue_timers;
 
 struct kqueue_timer {
+	intptr_t period;
 	int handle;
-	uint64_t nsecs;
-	uint64_t unacked;
+#ifndef EVFILT_USER
+	int continuous_fd;
+	unsigned int continuous_fd_valid:1;
+#endif
 	unsigned int is_continuous:1;
 };
 
@@ -90,6 +93,78 @@ static int kqueue_timer_cmp(void *obj, v
 	return timer1->handle == timer2->handle ? CMP_MATCH | CMP_STOP : 0;
 }
 
+#ifdef EVFILT_USER
+#define CONTINUOUS_EVFILT_TYPE EVFILT_USER
+static int kqueue_timer_init_continuous_event(struct kqueue_timer *timer)
+{
+	return 0;
+}
+
+static int kqueue_timer_enable_continuous_event(struct kqueue_timer *timer)
+{
+	struct kevent kev[2];
+
+	EV_SET(&kev[0], (uintptr_t)timer, EVFILT_USER, EV_ADD | EV_ENABLE,
+		0, 0, NULL);
+	EV_SET(&kev[1], (uintptr_t)timer, EVFILT_USER, 0, NOTE_TRIGGER,
+		0, NULL);
+	return kevent(timer->handle, kev, 2, NULL, 0, NULL);
+}
+
+static int kqueue_timer_disable_continuous_event(struct kqueue_timer *timer)
+{
+	struct kevent kev;
+
+	EV_SET(&kev, (uintptr_t)timer, EVFILT_USER, EV_DELETE, 0, 0, NULL);
+	return kevent(timer->handle, &kev, 1, NULL, 0, NULL);
+}
+
+static void kqueue_timer_fini_continuous_event(struct kqueue_timer *timer)
+{
+}
+
+#else /* EVFILT_USER */
+
+#define CONTINUOUS_EVFILT_TYPE EVFILT_READ
+static int kqueue_timer_init_continuous_event(struct kqueue_timer *timer)
+{
+	int pipefds[2];
+	int retval;
+
+	retval = pipe(pipefds);
+	if (retval == 0) {
+		timer->continuous_fd = pipefds[0];
+		timer->continuous_fd_valid = 1;
+		close(pipefds[1]);
+	}
+	return retval;
+}
+
+static void kqueue_timer_fini_continuous_event(struct kqueue_timer *timer)
+{
+	if (timer->continuous_fd_valid) {
+		close(timer->continuous_fd);
+	}
+}
+
+static int kqueue_timer_enable_continuous_event(struct kqueue_timer *timer)
+{
+	struct kevent kev;
+
+	EV_SET(&kev, timer->continuous_fd, EVFILT_READ, EV_ADD | EV_ENABLE,
+		0, 0, NULL);
+	return kevent(timer->handle, &kev, 1, NULL, 0, NULL);
+}
+
+static int kqueue_timer_disable_continuous_event(struct kqueue_timer *timer)
+{
+	struct kevent kev;
+
+	EV_SET(&kev, timer->continuous_fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
+	return kevent(timer->handle, &kev, 1, NULL, 0, NULL);
+}
+#endif
+
 static void timer_destroy(void *obj)
 {
 	struct kqueue_timer *timer = obj;
@@ -120,15 +195,25 @@ static int kqueue_timer_open(void)
 	int handle;
 
 	if (!(timer = ao2_alloc(sizeof(*timer), timer_destroy))) {
-		ast_log(LOG_ERROR, "Could not allocate memory for kqueue_timer structure\n");
+		ast_log(LOG_ERROR, "Alloc failed for kqueue_timer structure\n");
 		return -1;
 	}
+
 	if ((timer->handle = handle = kqueue()) < 0) {
-		ast_log(LOG_ERROR, "Failed to create kqueue timer: %s\n", strerror(errno));
+		ast_log(LOG_ERROR, "Failed to create kqueue fd: %s\n",
+			strerror(errno));
 		ao2_ref(timer, -1);
 		return -1;
 	}
 
+	if (kqueue_timer_init_continuous_event(timer) != 0) {
+		ast_log(LOG_ERROR, "Failed to create continuous event: %s\n",
+			strerror(errno));
+		ao2_ref(timer, -1);
+		return -1;
+	}
+	ast_debug(5, "[%d]: Create timer\n", timer->handle);
+
 	ao2_link(kqueue_timers, timer);
 	/* Get rid of the reference from the allocation */
 	ao2_ref(timer, -1);
@@ -143,54 +228,86 @@ static void kqueue_timer_close(int handl
 		return;
 	}
 
+	ast_debug(5, "[%d]: Timer close\n", our_timer->handle);
 	ao2_unlink(kqueue_timers, our_timer);
 	ao2_ref(our_timer, -1);
 }
 
-static void kqueue_set_nsecs(struct kqueue_timer *our_timer, uint64_t nsecs)
+/*
+ * Use the highest precision available that does not overflow
+ * the datatype kevent is using for time.
+ */
+static intptr_t kqueue_scale_period(unsigned int period_ns, int *units)
 {
-	struct timespec nowait = { 0, 1 };
-#ifdef HAVE_KEVENT64
-	struct kevent64_s kev;
-
-	EV_SET64(&kev, our_timer->handle, EVFILT_TIMER, EV_ADD | EV_ENABLE, NOTE_NSECONDS,
-		nsecs, 0, 0, 0);
-	kevent64(our_timer->handle, &kev, 1, NULL, 0, 0, &nowait);
-#else
-	struct kevent kev;
-
-	EV_SET(&kev, our_timer->handle, EVFILT_TIMER, EV_ADD | EV_ENABLE,
-#ifdef NOTE_NSECONDS
-		nsecs <= 0xFFffFFff ? NOTE_NSECONDS :
-#endif
-#ifdef NOTE_USECONDS
-		NOTE_USECONDS
-#else /* Milliseconds, if no constants are defined */
-		0
-#endif
-		,
+	uint64_t period = period_ns;
+	*units = 0;
 #ifdef NOTE_NSECONDS
-		nsecs <= 0xFFffFFff ? nsecs :
-#endif
+	if (period < INTPTR_MAX) {
+		*units = NOTE_NSECONDS;
+	} else {
 #ifdef NOTE_USECONDS
-	nsecs / 1000
-#else /* Milliseconds, if nothing else is defined */
-	nsecs / 1000000
-#endif
-	, NULL);
-	kevent(our_timer->handle, &kev, 1, NULL, 0, &nowait);
+		period /= 1000;
+		if (period < INTPTR_MAX) {
+			*units = NOTE_USECONDS;
+		} else {
+			period /= 1000;
+#ifdef NOTE_MSECONDS
+			*units = NOTE_MSECONDS;
+#endif	/* NOTE_MSECONDS */
+		}
+#else	/* NOTE_USECONDS */
+		period /= 1000000;
+#ifdef NOTE_MSECONDS
+		*units = NOTE_MSECONDS;
+#endif	/* NOTE_MSECONDS */
+#endif	/* NOTE_USECONDS */
+	}
+#else	/* NOTE_NSECONDS */
+	period /= 1000000;
 #endif
+	if (period > INTPTR_MAX) {
+		period = INTPTR_MAX;
+	}
+	return period;
 }
 
 static int kqueue_timer_set_rate(int handle, unsigned int rate)
 {
+	struct kevent kev;
 	struct kqueue_timer *our_timer;
+	uint64_t period_ns;
+	int flags;
+	int units;
+	int retval;
 
 	if (!(our_timer = lookup_timer(handle))) {
 		return -1;
 	}
 
-	kqueue_set_nsecs(our_timer, (our_timer->nsecs = rate ? (long) (1000000000 / rate) : 0L));
+	if (rate == 0) {
+		if (our_timer->period == 0) {
+			ao2_ref(our_timer, -1);
+			return 0;
+		}
+		flags = EV_DELETE;
+		our_timer->period = 0;
+		units = 0;
+	} else {
+		flags = EV_ADD | EV_ENABLE;
+		period_ns = (uint64_t)1000000000 / rate;
+		our_timer->period = kqueue_scale_period(period_ns, &units);
+	}
+	ast_debug(5, "[%d]: Set rate %u:%ju\n",
+		our_timer->handle, units, (uintmax_t)our_timer->period);
+	EV_SET(&kev, our_timer->handle, EVFILT_TIMER, flags, units,
+		our_timer->period, NULL);
+	retval =  kevent(our_timer->handle, &kev, 1, NULL, 0, NULL);
+
+	if (retval == -1) {
+		ast_log(LOG_ERROR, "[%d]: Error queueing timer: %s\n",
+			our_timer->handle, strerror(errno));
+	}
+
 	ao2_ref(our_timer, -1);
 
 	return 0;
@@ -198,75 +315,113 @@ static int kqueue_timer_set_rate(int han
 
 static int kqueue_timer_ack(int handle, unsigned int quantity)
 {
+	static struct timespec ts_nowait = { 0, 0 };
 	struct kqueue_timer *our_timer;
+	struct kevent kev[2];
+	int i, retval;
 
 	if (!(our_timer = lookup_timer(handle))) {
 		return -1;
 	}
 
-	if (our_timer->unacked < quantity) {
-		ast_debug(1, "Acking more events than have expired?!!\n");
-		our_timer->unacked = 0;
+	retval = kevent(our_timer->handle, NULL, 0, kev, 2, &ts_nowait);
+	if (retval == -1) {
+		ast_log(LOG_ERROR, "[%d]: Error sampling kqueue: %s\n",
+			our_timer->handle, strerror(errno));
 		ao2_ref(our_timer, -1);
 		return -1;
-	} else {
-		our_timer->unacked -= quantity;
+	}
+
+	for (i = 0; i < retval; i++) {
+		switch (kev[i].filter) {
+		case EVFILT_TIMER:
+			if (kev[i].data > quantity) {
+				ast_log(LOG_ERROR, "[%d]: Missed %ju\n",
+					our_timer->handle,
+					(uintmax_t)kev[i].data - quantity);
+			}
+			break;
+		case CONTINUOUS_EVFILT_TYPE:
+			if (!our_timer->is_continuous) {
+				ast_log(LOG_ERROR,
+					"[%d]: Spurious user event\n",
+					our_timer->handle);
+			}
+			break;
+		default:
+			ast_log(LOG_ERROR, "[%d]: Spurious kevent type %d.\n",
+				our_timer->handle, kev[i].filter);
+		}
 	}
 
 	ao2_ref(our_timer, -1);
+
 	return 0;
 }
 
 static int kqueue_timer_enable_continuous(int handle)
 {
 	struct kqueue_timer *our_timer;
+	int retval;
 
 	if (!(our_timer = lookup_timer(handle))) {
 		return -1;
 	}
 
-	kqueue_set_nsecs(our_timer, 1);
-	our_timer->is_continuous = 1;
-	our_timer->unacked = 0;
+	if (!our_timer->is_continuous) {
+		ast_debug(5, "[%d]: Enable continuous\n", our_timer->handle);
+		retval = kqueue_timer_enable_continuous_event(our_timer);
+		if (retval == -1) {
+			ast_log(LOG_ERROR,
+				"[%d]: Error signalling continuous event: %s\n",
+				our_timer->handle, strerror(errno));
+		}
+		our_timer->is_continuous = 1;
+	}
+
 	ao2_ref(our_timer, -1);
+
 	return 0;
 }
 
 static int kqueue_timer_disable_continuous(int handle)
 {
 	struct kqueue_timer *our_timer;
+	int retval;
 
 	if (!(our_timer = lookup_timer(handle))) {
 		return -1;
 	}
 
-	kqueue_set_nsecs(our_timer, our_timer->nsecs);
-	our_timer->is_continuous = 0;
-	our_timer->unacked = 0;
+	if (our_timer->is_continuous) {
+		ast_debug(5, "[%d]: Disable Continuous\n", our_timer->handle);
+		retval = kqueue_timer_disable_continuous_event(our_timer);
+		if (retval == -1) {
+			ast_log(LOG_ERROR,
+				"[%d]: Error clearing continuous event: %s\n",
+				our_timer->handle, strerror(errno));
+		}
+		our_timer->is_continuous = 0;
+	}
+
 	ao2_ref(our_timer, -1);
+
 	return 0;
 }
 
 static enum ast_timer_event kqueue_timer_get_event(int handle)
 {
-	enum ast_timer_event res = -1;
 	struct kqueue_timer *our_timer;
-	struct timespec sixty_seconds = { 60, 0 };
-	struct kevent kev;
+	enum ast_timer_event res;
 
 	if (!(our_timer = lookup_timer(handle))) {
-		return -1;
+		return AST_TIMING_EVENT_EXPIRED;
 	}
 
-	/* If we have non-ACKed events, just return immediately */
-	if (our_timer->unacked == 0) {
-		if (kevent(handle, NULL, 0, &kev, 1, &sixty_seconds) > 0) {
-			our_timer->unacked += kev.data;
-		}
-	}
-
-	if (our_timer->unacked > 0) {
-		res = our_timer->is_continuous ? AST_TIMING_EVENT_CONTINUOUS : AST_TIMING_EVENT_EXPIRED;
+	if (our_timer->is_continuous) {
+		res = AST_TIMING_EVENT_CONTINUOUS;
+	} else {
+		res = AST_TIMING_EVENT_EXPIRED;
 	}
 
 	ao2_ref(our_timer, -1);
@@ -275,8 +430,7 @@ static enum ast_timer_event kqueue_timer
 
 static unsigned int kqueue_timer_get_max_rate(int handle)
 {
-	/* Actually, the max rate is 2^64-1 seconds, but that's not representable in a 32-bit integer. */
-	return UINT_MAX;
+	return INTPTR_MAX > UINT_MAX ? UINT_MAX : INTPTR_MAX;
 }
 
 #ifdef TEST_FRAMEWORK
@@ -331,13 +485,12 @@ AST_TEST_DEFINE(test_kqueue_timing)
 			res = AST_TEST_FAIL;
 			break;
 		}
-#if 0
-		if (kt->unacked == 0) {
-			ast_test_status_update(test, "Unacked events is 0, but there should be at least 1.\n");
-			res = AST_TEST_FAIL;
+		if (kqueue_timer_ack(handle, 1) != 0) {
+			ast_test_status_update(test, "Acking event failed.\n");
+			res = AST_TEST_FAiL;
 			break;
 		}
-#endif
+
 		kqueue_timer_enable_continuous(handle);
 		start = ast_tvnow();
 		for (i = 0; i < 100; i++) {
@@ -351,15 +504,15 @@ AST_TEST_DEFINE(test_kqueue_timing)
 				res = AST_TEST_FAIL;
 				break;
 			}
+			if (kqueue_timer_ack(handle, 1) != 0) {
+				ast_test_status_update(test, "Acking event failed.\n");
+				res = AST_TEST_FAIL;
+			}
+
 		}
+
 		diff = ast_tvdiff_us(ast_tvnow(), start);
 		ast_test_status_update(test, "diff is %llu\n", diff);
-		/*
-		if (abs(diff - kt->unacked) == 0) {
-			ast_test_status_update(test, "Unacked events should be around 1000, not %llu\n", kt->unacked);
-			res = AST_TEST_FAIL;
-		}
-		*/
 	} while (0);
 	kqueue_timer_close(handle);
 	return res;
