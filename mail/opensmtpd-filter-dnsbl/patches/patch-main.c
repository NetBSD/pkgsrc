$NetBSD: patch-main.c,v 1.2 2023/09/08 21:05:37 vins Exp $

* Provide an implementation of recallocarray().
* Provide compatibility functions for OpenBSD's libevent
  (pulled from OpenSMTD/openbsd-compat).

--- main.c.orig	2021-10-27 09:33:56.000000000 +0000
+++ main.c
@@ -1,5 +1,6 @@
 /*
  * Copyright (c) 2019 Martijn van Duren <martijn@openbsd.org>
+ * Copyright (c) 2012 Eric Faurot <eric@openbsd.org>
  *
  * Permission to use, copy, modify, and distribute this software for any
  * purpose with or without fee is hereby granted, provided that the above
@@ -30,6 +31,104 @@
 #include <asr.h>
 
 #include "opensmtpd.h"
+#include "compat.h"
+
+void *recallocarray(void *ptr, size_t om, size_t m, size_t n)
+{
+	void *newptr;
+	size_t old_size, new_size;
+
+	if (n && m > -1 / n) {
+		errno = ENOMEM;
+		return 0;
+	}
+	new_size = m * n;
+
+	if (n && om > -1 / n) {
+		errno = EINVAL;
+		return 0;
+	}
+	old_size = om * n;
+
+	newptr = calloc(m, n);
+	if (!newptr)
+		return ptr;
+
+	if (new_size <= old_size) {
+		memcpy((char *) newptr, ptr, new_size);
+	}
+	else {
+		memcpy((char *) newptr, ptr, old_size);
+		memset((char *) newptr + old_size, 0, new_size - old_size);
+	}
+
+	memset(ptr, 0, old_size);
+	free(ptr);
+
+	return newptr;
+}
+
+struct event_asr {
+	struct event	 ev;
+	struct asr_query *async;
+	void		(*cb)(struct asr_result *, void *);
+	void		*arg;
+};
+
+struct event_asr * event_asr_run(struct asr_query *,
+    void (*)(struct asr_result *, void *), void *);
+void event_asr_abort(struct event_asr *);
+
+static void
+event_asr_dispatch(int fd __attribute__((__unused__)),
+    short ev __attribute__((__unused__)), void *arg)
+{
+	struct event_asr	*eva = arg;
+	struct asr_result	 ar;
+	struct timeval		 tv;
+
+	event_del(&eva->ev);
+
+	if (asr_run(eva->async, &ar)) {
+		eva->cb(&ar, eva->arg);
+		free(eva);
+	} else {
+		event_set(&eva->ev, ar.ar_fd,
+		    ar.ar_cond == ASR_WANT_READ ? EV_READ : EV_WRITE,
+		    event_asr_dispatch, eva);
+		tv.tv_sec = ar.ar_timeout / 1000;
+		tv.tv_usec = (ar.ar_timeout % 1000) * 1000;
+		event_add(&eva->ev, &tv);
+	}
+}
+
+struct event_asr *
+event_asr_run(struct asr_query *async, void (*cb)(struct asr_result *, void *),
+    void *arg)
+{
+	struct event_asr *eva;
+	struct timeval tv;
+
+	eva = calloc(1, sizeof *eva);
+	if (eva == NULL)
+		return (NULL);
+	eva->async = async;
+	eva->cb = cb;
+	eva->arg = arg;
+	tv.tv_sec = 0;
+	tv.tv_usec = 0;
+	evtimer_set(&eva->ev, event_asr_dispatch, eva);
+	evtimer_add(&eva->ev, &tv);
+	return (eva);
+}
+
+void
+event_asr_abort(struct event_asr *eva)
+{
+	asr_abort(eva->async);
+	event_del(&eva->ev);
+	free(eva);
+}
 
 struct dnsbl_session;
 
