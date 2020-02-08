$NetBSD: patch-mozilla_nsprpub_pr_src_pthreads_ptsynch.c,v 1.1 2020/02/08 22:20:26 kamil Exp $

Workaround buggy usage of pthread_equal().

--- mozilla/nsprpub/pr/src/pthreads/ptsynch.c.orig	2018-07-09 19:54:54.000000000 +0000
+++ mozilla/nsprpub/pr/src/pthreads/ptsynch.c
@@ -30,6 +30,13 @@ static pthread_t pt_zero_tid;  /* a null
 #endif  /* defined(_PR_DCETHREADS) */
 #endif  /* defined(DEBUG) */
 
+/* XXX, pthread_equal() is misused to compare non-valid thread pointers */
+static int
+pt_pthread_equal(pthread_t t1, pthread_t t2)
+{
+	return t1 == t2;
+}
+
 #if defined(FREEBSD)
 /*
  * On older versions of FreeBSD, pthread_mutex_trylock returns EDEADLK.
@@ -198,9 +205,9 @@ PR_IMPLEMENT(PRStatus) PR_Unlock(PRLock 
     PR_ASSERT(lock != NULL);
     PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(lock->mutex));
     PR_ASSERT(PR_TRUE == lock->locked);
-    PR_ASSERT(pthread_equal(lock->owner, self));
+    PR_ASSERT(pt_pthread_equal(lock->owner, self));
 
-    if (!lock->locked || !pthread_equal(lock->owner, self))
+    if (!lock->locked || !pt_pthread_equal(lock->owner, self))
         return PR_FAILURE;
 
     lock->locked = PR_FALSE;
@@ -223,7 +230,7 @@ PR_IMPLEMENT(void) PR_AssertCurrentThrea
      * to the correctness of PR_AssertCurrentThreadOwnsLock(), but 
      * this particular order makes the assertion more likely to
      * catch errors. */
-    PR_ASSERT(lock->locked && pthread_equal(lock->owner, pthread_self()));
+    PR_ASSERT(lock->locked && pt_pthread_equal(lock->owner, pthread_self()));
 }
 
 /**************************************************************/
@@ -284,7 +291,7 @@ static void pt_PostNotifyToCvar(PRCondVa
     _PT_Notified *notified = &cvar->lock->notified;
 
     PR_ASSERT(PR_TRUE == cvar->lock->locked);
-    PR_ASSERT(pthread_equal(cvar->lock->owner, pthread_self()));
+    PR_ASSERT(pt_pthread_equal(cvar->lock->owner, pthread_self()));
     PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(cvar->lock->mutex));
 
     while (1)
@@ -367,7 +374,7 @@ PR_IMPLEMENT(PRStatus) PR_WaitCondVar(PR
     PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(cvar->lock->mutex));
     PR_ASSERT(PR_TRUE == cvar->lock->locked);
     /* and it better be by us */
-    PR_ASSERT(pthread_equal(cvar->lock->owner, pthread_self()));
+    PR_ASSERT(pt_pthread_equal(cvar->lock->owner, pthread_self()));
 
     if (_PT_THREAD_INTERRUPTED(thred)) goto aborted;
 
@@ -565,7 +572,7 @@ PR_IMPLEMENT(PRIntn) PR_GetMonitorEntryC
 
     rv = pthread_mutex_lock(&mon->lock);
     PR_ASSERT(0 == rv);
-    if (pthread_equal(mon->owner, self))
+    if (pt_pthread_equal(mon->owner, self))
         count = mon->entryCount;
     rv = pthread_mutex_unlock(&mon->lock);
     PR_ASSERT(0 == rv);
@@ -580,7 +587,7 @@ PR_IMPLEMENT(void) PR_AssertCurrentThrea
     rv = pthread_mutex_lock(&mon->lock);
     PR_ASSERT(0 == rv);
     PR_ASSERT(mon->entryCount != 0 &&
-              pthread_equal(mon->owner, pthread_self()));
+              pt_pthread_equal(mon->owner, pthread_self()));
     rv = pthread_mutex_unlock(&mon->lock);
     PR_ASSERT(0 == rv);
 #endif
@@ -596,7 +603,7 @@ PR_IMPLEMENT(void) PR_EnterMonitor(PRMon
     PR_ASSERT(0 == rv);
     if (mon->entryCount != 0)
     {
-        if (pthread_equal(mon->owner, self))
+        if (pt_pthread_equal(mon->owner, self))
             goto done;
         while (mon->entryCount != 0)
         {
@@ -627,8 +634,8 @@ PR_IMPLEMENT(PRStatus) PR_ExitMonitor(PR
     PR_ASSERT(0 == rv);
     /* the entries should be > 0 and we'd better be the owner */
     PR_ASSERT(mon->entryCount > 0);
-    PR_ASSERT(pthread_equal(mon->owner, self));
-    if (mon->entryCount == 0 || !pthread_equal(mon->owner, self))
+    PR_ASSERT(pt_pthread_equal(mon->owner, self));
+    if (mon->entryCount == 0 || !pt_pthread_equal(mon->owner, self))
     {
         rv = pthread_mutex_unlock(&mon->lock);
         PR_ASSERT(0 == rv);
@@ -675,7 +682,7 @@ PR_IMPLEMENT(PRStatus) PR_Wait(PRMonitor
     /* the entries better be positive */
     PR_ASSERT(mon->entryCount > 0);
     /* and it better be owned by us */
-    PR_ASSERT(pthread_equal(mon->owner, pthread_self()));
+    PR_ASSERT(pt_pthread_equal(mon->owner, pthread_self()));
 
     /* tuck these away 'till later */
     saved_entries = mon->entryCount; 
