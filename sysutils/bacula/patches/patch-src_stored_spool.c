$NetBSD: patch-src_stored_spool.c,v 1.1 2023/03/26 19:34:11 markd Exp $

NetBSD 10 doesn't like using uninitialised mutex's
https://gitlab.bacula.org/bacula-community-edition/bacula-community/-/issues/2678

--- src/stored/spool.c.orig	2022-08-06 03:13:35.000000000 +1200
+++ src/stored/spool.c	2023-03-15 16:44:21.600839247 +1300
@@ -229,6 +229,21 @@
     * in rdev and rdcr.
     */
    rdev = New(file_dev);
+
+   /*
+    * VUW patch: on NetBSD a mutex needs to be properly initialised otherwise
+    * pthread_mutex_lock() returns an error.  The only one that we *think*
+    * matters here is rdev->dcrs_mutex, but a better fix would be to properly
+    * initialise the rdev object ...
+    */
+   int errstat;
+   if ((errstat = pthread_mutex_init(&rdev->dcrs_mutex, NULL)) != 0) {
+      berrno be;
+      rdev->dev_errno = errstat;
+      Mmsg1(rdev->errmsg, _("Unable to init dcrs mutex: ERR=%s\n"), be.bstrerror(errstat));
+      Jmsg0(jcr, M_ERROR_TERM, 0, rdev->errmsg);
+   }
+
    rdev->dev_name = get_memory(strlen(spool_name)+1);
    bstrncpy(rdev->dev_name, spool_name, strlen(spool_name)+1);
    rdev->errmsg = get_pool_memory(PM_EMSG);
