$NetBSD: patch-src_runtime_cgo_gcc__solaris__amd64.c,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- /dev/null
+++ src/runtime/cgo/gcc_solaris_amd64.c
@@ -0,0 +1,70 @@
+// Copyright 2009 The Go Authors.  All rights reserved.
+// Use of this source code is governed by a BSD-style
+// license that can be found in the LICENSE file.
+
+#include <pthread.h>
+#include <string.h>
+#include <signal.h>
+#include "libcgo.h"
+
+static void* threadentry(void*);
+static void (*setg_gcc)(void*);
+
+void
+x_cgo_init(G *g, void (*setg)(void*))
+{
+	pthread_attr_t attr;
+	size_t size;
+
+	setg_gcc = setg;
+	pthread_attr_init(&attr);
+	if (pthread_attr_getstack(&attr, (void **)&g->stacklo, &size) != 0)
+		perror("runtime/cgo: pthread_attr_getstack failed");
+	g->stackhi = (uintptr_t)g->stacklo + 8192;
+	pthread_attr_destroy(&attr);
+}
+
+void
+_cgo_sys_thread_start(ThreadStart *ts)
+{
+	pthread_attr_t attr;
+	sigset_t ign, oset;
+	pthread_t p;
+	size_t size;
+	int err;
+
+	sigfillset(&ign);
+	pthread_sigmask(SIG_SETMASK, &ign, &oset);
+
+	pthread_attr_init(&attr);
+
+	if (pthread_attr_getstack(&attr, (void **)&ts->g->stacklo, &size) != 0)
+		perror("runtime/cgo: pthread_attr_getstack failed");
+	ts->g->stackhi = (uintptr_t)ts->g->stacklo + 8192;
+	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
+	err = pthread_create(&p, &attr, threadentry, ts);
+
+	pthread_sigmask(SIG_SETMASK, &oset, nil);
+
+	if (err != 0) {
+		fprintf(stderr, "runtime/cgo: pthread_create failed: %s\n", strerror(err));
+		abort();
+	}
+}
+
+static void*
+threadentry(void *v)
+{
+	ThreadStart ts;
+
+	ts = *(ThreadStart*)v;
+	free(v);
+
+	/*
+	 * Set specific keys.
+	 */
+	setg_gcc((void*)ts.g);
+
+	crosscall_amd64(ts.fn);
+	return nil;
+}
