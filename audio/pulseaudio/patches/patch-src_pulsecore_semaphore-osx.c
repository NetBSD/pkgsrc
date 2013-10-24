$NetBSD: patch-src_pulsecore_semaphore-osx.c,v 1.1 2013/10/24 17:48:53 jperkin Exp $

Add patch to fix OSX build, from:

  https://bugs.freedesktop.org/attachment.cgi?id=77310

--- src/pulsecore/semaphore-osx.c
+++ src/pulsecore/semaphore-osx.c
@@ -1,7 +1,8 @@
 /***
   This file is part of PulseAudio.
 
-  Copyright 2009 Kim Lester <kim@dfusion.com.au>
+  Copyright 2006 Lennart Poettering
+  Copyright 2013 Albert Zeyer
 
   PulseAudio is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
@@ -23,40 +24,72 @@
 #include <config.h>
 #endif
 
-#include <Multiprocessing.h>
+#include <stdio.h>
+#include <errno.h>
+#include <pthread.h>
+#include <semaphore.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 #include <pulse/xmalloc.h>
 #include <pulsecore/macro.h>
+#include <pulsecore/atomic.h>
+#include <pulsecore/core-util.h>
 
 #include "semaphore.h"
 
+/*
+OSX doesn't support unnamed semaphores (via sem_init).
+Thus, we use a counter to give them enumerated names.
+*/
+
+static pa_atomic_t id_counter = PA_ATOMIC_INIT(0);
+
 struct pa_semaphore {
-    MPSemaphoreID sema;
+    sem_t* sem;
+    int id;
 };
 
-pa_semaphore* pa_semaphore_new(unsigned int value) {
-    /* NOTE: Can't assume boolean - ie value = 0,1, so use UINT_MAX (boolean more efficient ?) */
+static char *sem_name(char *fn, size_t l, int id) {
+    pa_snprintf(fn, l, "/pulse-sem-%u-%u", getpid(), id);
+    return fn;
+}
+
+pa_semaphore* pa_semaphore_new(unsigned value) {
     pa_semaphore *s;
 
     s = pa_xnew(pa_semaphore, 1);
-    pa_assert_se(MPCreateSemaphore(UINT_MAX, value, &s->sema) == 0);
-
+    s->id = pa_atomic_inc(&id_counter);
+    char fn[32]; sem_name(fn, sizeof(fn), s->id);
+    sem_unlink(fn); // in case it already exists
+    if((s->sem = sem_open(fn, O_CREAT|O_EXCL, 0700, value)) == SEM_FAILED) {
+        perror("pa_semaphore_new: sem_open");
+        abort();
+    }
     return s;
 }
 
 void pa_semaphore_free(pa_semaphore *s) {
     pa_assert(s);
-    pa_assert_se(MPDeleteSemaphore(s->sema) == 0);
+    pa_assert_se(sem_close(s->sem) == 0);
+    char fn[32]; sem_name(fn, sizeof(fn), s->id);
+    if(sem_unlink(fn) != 0)
+        perror("pa_semaphore_free: sem_unlink");
     pa_xfree(s);
 }
 
 void pa_semaphore_post(pa_semaphore *s) {
     pa_assert(s);
-    pa_assert_se(MPSignalSemaphore(s->sema) == 0);
+    pa_assert_se(sem_post(s->sem) == 0);
 }
 
 void pa_semaphore_wait(pa_semaphore *s) {
+    int ret;
     pa_assert(s);
-    /* should probably check return value (-ve is error), noErr is ok. */
-    pa_assert_se(MPWaitOnSemaphore(s->sema, kDurationForever) == 0);
+
+    do {
+        ret = sem_wait(s->sem);
+    } while (ret < 0 && errno == EINTR);
+
+    pa_assert(ret == 0);
 }
