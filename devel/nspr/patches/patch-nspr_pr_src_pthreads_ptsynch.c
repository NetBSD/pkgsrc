$NetBSD: patch-nspr_pr_src_pthreads_ptsynch.c,v 1.3 2024/10/22 12:52:02 ryoon Exp $

* Do not use pthread_equal() for non-valid thread pointers.
  From kamin@ on source-changes-d@NetBSD.org.
  https://mail-index.netbsd.org/source-changes-d/2020/02/03/msg012143.html

https://bugzilla.mozilla.org/show_bug.cgi?id=1718838

--- nspr/pr/src/pthreads/ptsynch.c.orig	2024-10-21 11:31:57.000000000 +0000
+++ nspr/pr/src/pthreads/ptsynch.c
@@ -25,6 +25,13 @@ static pthread_condattr_t _pt_cvar_attr;
 extern PTDebug pt_debug; /* this is shared between several modules */
 #  endif                 /* defined(DEBUG) */
 
+/* XXX, pthread_equal() is misused to compare non-valid thread pointers */
+static int
+pt_pthread_equal(pthread_t t1, pthread_t t2)
+{
+	return t1 == t2;
+}
+
 #  if defined(FREEBSD)
 /*
  * On older versions of FreeBSD, pthread_mutex_trylock returns EDEADLK.
@@ -181,9 +188,9 @@ PR_IMPLEMENT(PRStatus) PR_Unlock(PRLock*
   PR_ASSERT(lock != NULL);
   PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(lock->mutex));
   PR_ASSERT(PR_TRUE == lock->locked);
-  PR_ASSERT(pthread_equal(lock->owner, self));
+  PR_ASSERT(pt_pthread_equal(lock->owner, self));
 
-  if (!lock->locked || !pthread_equal(lock->owner, self)) {
+  if (!lock->locked || !pt_pthread_equal(lock->owner, self)) {
     return PR_FAILURE;
   }
 
@@ -207,7 +214,7 @@ PR_IMPLEMENT(void) PR_AssertCurrentThrea
    * to the correctness of PR_AssertCurrentThreadOwnsLock(), but
    * this particular order makes the assertion more likely to
    * catch errors. */
-  PR_ASSERT(lock->locked && pthread_equal(lock->owner, pthread_self()));
+  PR_ASSERT(lock->locked && pt_pthread_equal(lock->owner, pthread_self()));
 }
 
 /**************************************************************/
@@ -260,7 +267,7 @@ static void pt_PostNotifyToCvar(PRCondVa
   _PT_Notified* notified = &cvar->lock->notified;
 
   PR_ASSERT(PR_TRUE == cvar->lock->locked);
-  PR_ASSERT(pthread_equal(cvar->lock->owner, pthread_self()));
+  PR_ASSERT(pt_pthread_equal(cvar->lock->owner, pthread_self()));
   PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(cvar->lock->mutex));
 
   while (1) {
@@ -336,7 +343,7 @@ PR_IMPLEMENT(PRStatus) PR_WaitCondVar(PR
   PR_ASSERT(_PT_PTHREAD_MUTEX_IS_LOCKED(cvar->lock->mutex));
   PR_ASSERT(PR_TRUE == cvar->lock->locked);
   /* and it better be by us */
-  PR_ASSERT(pthread_equal(cvar->lock->owner, pthread_self()));
+  PR_ASSERT(pt_pthread_equal(cvar->lock->owner, pthread_self()));
 
   if (_PT_THREAD_INTERRUPTED(thred)) {
     goto aborted;
@@ -535,7 +542,7 @@ PR_IMPLEMENT(PRIntn) PR_GetMonitorEntryC
 
   rv = pthread_mutex_lock(&mon->lock);
   PR_ASSERT(0 == rv);
-  if (pthread_equal(mon->owner, self)) {
+  if (pt_pthread_equal(mon->owner, self)) {
     count = mon->entryCount;
   }
   rv = pthread_mutex_unlock(&mon->lock);
@@ -549,7 +556,7 @@ PR_IMPLEMENT(void) PR_AssertCurrentThrea
 
   rv = pthread_mutex_lock(&mon->lock);
   PR_ASSERT(0 == rv);
-  PR_ASSERT(mon->entryCount != 0 && pthread_equal(mon->owner, pthread_self()));
+  PR_ASSERT(mon->entryCount != 0 && pt_pthread_equal(mon->owner, pthread_self()));
   rv = pthread_mutex_unlock(&mon->lock);
   PR_ASSERT(0 == rv);
 #  endif
@@ -563,7 +570,7 @@ PR_IMPLEMENT(void) PR_EnterMonitor(PRMon
   rv = pthread_mutex_lock(&mon->lock);
   PR_ASSERT(0 == rv);
   if (mon->entryCount != 0) {
-    if (pthread_equal(mon->owner, self)) {
+    if (pt_pthread_equal(mon->owner, self)) {
       goto done;
     }
     while (mon->entryCount != 0) {
@@ -593,8 +600,8 @@ PR_IMPLEMENT(PRStatus) PR_ExitMonitor(PR
   PR_ASSERT(0 == rv);
   /* the entries should be > 0 and we'd better be the owner */
   PR_ASSERT(mon->entryCount > 0);
-  PR_ASSERT(pthread_equal(mon->owner, self));
-  if (mon->entryCount == 0 || !pthread_equal(mon->owner, self)) {
+  PR_ASSERT(pt_pthread_equal(mon->owner, self));
+  if (mon->entryCount == 0 || !pt_pthread_equal(mon->owner, self)) {
     rv = pthread_mutex_unlock(&mon->lock);
     PR_ASSERT(0 == rv);
     return PR_FAILURE;
@@ -638,7 +645,7 @@ PR_IMPLEMENT(PRStatus) PR_Wait(PRMonitor
   /* the entries better be positive */
   PR_ASSERT(mon->entryCount > 0);
   /* and it better be owned by us */
-  PR_ASSERT(pthread_equal(mon->owner, pthread_self()));
+  PR_ASSERT(pt_pthread_equal(mon->owner, pthread_self()));
 
   /* tuck these away 'till later */
   saved_entries = mon->entryCount;
