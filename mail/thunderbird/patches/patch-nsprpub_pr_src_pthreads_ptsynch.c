$NetBSD: patch-nsprpub_pr_src_pthreads_ptsynch.c,v 1.6 2026/09/26 07:45:51 ryoon Exp $

firefox: Workaround broken pthread_equal() usage

Switch to an internal version of pthread_equal() without sanity checks.

Problems detected on NetBSD 9.99.46.

https://bugzilla.mozilla.org/show_bug.cgi?id=1718838

--- nsprpub/pr/src/pthreads/ptsynch.c.orig	2026-08-26 21:11:48.000000000 +0000
+++ nsprpub/pr/src/pthreads/ptsynch.c
@@ -24,6 +24,13 @@ extern PTDebug pt_debug; /* this is shared between sev
 extern PTDebug pt_debug; /* this is shared between several modules */
 #endif                   /* defined(DEBUG) */
 
+/* XXX, pt_pthread_equal() is misused to compare non-valid thread pointers */
+static int
+pt_pt_pthread_equal(pthread_t t1, pthread_t t2)
+{
+	return t1 == t2;
+}
+
 #if defined(FREEBSD)
 /*
  * On older versions of FreeBSD, pthread_mutex_trylock returns EDEADLK.
@@ -194,9 +201,9 @@ PR_Unlock(PRLock* lock)
     PR_ASSERT(lock != NULL);
     PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(lock->mutex));
     PR_ASSERT(PR_TRUE == lock->locked);
-    PR_ASSERT(pthread_equal(lock->owner, self));
+    PR_ASSERT(pt_pthread_equal(lock->owner, self));
 
-    if (!lock->locked || !pthread_equal(lock->owner, self)) {
+    if (!lock->locked || !pt_pthread_equal(lock->owner, self)) {
         return PR_FAILURE;
     }
 
@@ -222,7 +229,7 @@ PR_AssertCurrentThreadOwnsLock(PRLock* lock)
      * to the correctness of PR_AssertCurrentThreadOwnsLock(), but
      * this particular order makes the assertion more likely to
      * catch errors. */
-    PR_ASSERT(lock->locked && pthread_equal(lock->owner, pthread_self()));
+    PR_ASSERT(lock->locked && pt_pthread_equal(lock->owner, pthread_self()));
 }
 
 /**************************************************************/
@@ -279,7 +286,7 @@ pt_PostNotifyToCvar(PRCondVar* cvar, PRBool broadcast)
     _PT_Notified* notified = &cvar->lock->notified;
 
     PR_ASSERT(PR_TRUE == cvar->lock->locked);
-    PR_ASSERT(pthread_equal(cvar->lock->owner, pthread_self()));
+    PR_ASSERT(pt_pthread_equal(cvar->lock->owner, pthread_self()));
     PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(cvar->lock->mutex));
 
     while (1) {
@@ -361,7 +368,7 @@ PR_WaitCondVar(PRCondVar* cvar, PRIntervalTime timeout
     PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(cvar->lock->mutex));
     PR_ASSERT(PR_TRUE == cvar->lock->locked);
     /* and it better be by us */
-    PR_ASSERT(pthread_equal(cvar->lock->owner, pthread_self()));
+    PR_ASSERT(pt_pthread_equal(cvar->lock->owner, pthread_self()));
 
     if (_PT_THREAD_INTERRUPTED(thred)) {
         goto aborted;
@@ -576,7 +583,7 @@ PR_GetMonitorEntryCount(PRMonitor* mon)
 
     rv = pthread_mutex_lock(&mon->lock);
     PR_ASSERT(0 == rv);
-    if (pthread_equal(mon->owner, self)) {
+    if (pt_pthread_equal(mon->owner, self)) {
         count = mon->entryCount;
     }
     rv = pthread_mutex_unlock(&mon->lock);
@@ -592,7 +599,7 @@ PR_AssertCurrentThreadInMonitor(PRMonitor* mon)
 
     rv = pthread_mutex_lock(&mon->lock);
     PR_ASSERT(0 == rv);
-    PR_ASSERT(mon->entryCount != 0 && pthread_equal(mon->owner, pthread_self()));
+    PR_ASSERT(mon->entryCount != 0 && pt_pthread_equal(mon->owner, pthread_self()));
     rv = pthread_mutex_unlock(&mon->lock);
     PR_ASSERT(0 == rv);
 #endif
@@ -608,7 +615,7 @@ PR_EnterMonitor(PRMonitor* mon)
     rv = pthread_mutex_lock(&mon->lock);
     PR_ASSERT(0 == rv);
     if (mon->entryCount != 0) {
-        if (pthread_equal(mon->owner, self)) {
+        if (pt_pthread_equal(mon->owner, self)) {
             goto done;
         }
         while (mon->entryCount != 0) {
@@ -640,8 +647,8 @@ PR_ExitMonitor(PRMonitor* mon)
     PR_ASSERT(0 == rv);
     /* the entries should be > 0 and we'd better be the owner */
     PR_ASSERT(mon->entryCount > 0);
-    PR_ASSERT(pthread_equal(mon->owner, self));
-    if (mon->entryCount == 0 || !pthread_equal(mon->owner, self)) {
+    PR_ASSERT(pt_pthread_equal(mon->owner, self));
+    if (mon->entryCount == 0 || !pt_pthread_equal(mon->owner, self)) {
         rv = pthread_mutex_unlock(&mon->lock);
         PR_ASSERT(0 == rv);
         return PR_FAILURE;
@@ -687,7 +694,7 @@ PR_Wait(PRMonitor* mon, PRIntervalTime timeout)
     /* the entries better be positive */
     PR_ASSERT(mon->entryCount > 0);
     /* and it better be owned by us */
-    PR_ASSERT(pthread_equal(mon->owner, pthread_self()));
+    PR_ASSERT(pt_pthread_equal(mon->owner, pthread_self()));
 
     /* tuck these away 'till later */
     saved_entries = mon->entryCount;
