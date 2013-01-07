$NetBSD: patch-src-auth-cellconfig.c,v 1.1 2013/01/07 00:03:16 christos Exp $

--- src/auth/cellconfig.c.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/auth/cellconfig.c	2013-01-06 18:00:28.000000000 -0500
@@ -976,6 +976,11 @@
     int pass = 0;
     char *IANAname = (char *) afsconf_FindIANAName(service);
     int tservice = afsconf_FindService(service);
+#ifdef __NetBSD__
+    res_state res;
+#else
+#define res (&_res)
+#endif
 
     realCellName = NULL;
 
@@ -994,15 +999,18 @@
 	return AFSCONF_NOTFOUND;	/* service not found */
 
 #ifdef HAVE_RES_RETRANSRETRY
-    if ((_res.options & RES_INIT) == 0 && res_init() == -1)
+#ifdef __NetBSD__
+    res = __res_get_state();
+#else
+    if ((res->options & RES_INIT) == 0 && res_init() == -1)
       return (0);
-
+#endif
     /*
      * Rx timeout is typically 56 seconds; limit user experience to
      * similar timeout
      */
-    _res.retrans = 18;
-    _res.retry = 3;
+    res->retrans = 18;
+    res->retry = 3;
 #endif
 
  retryafsdb:
@@ -1030,9 +1038,13 @@
     }
     if ((code < 0) || (code >= fullnamelength))
 	goto findservererror;
+#ifdef __NetBSD__
+    len = res_nsearch(res, dotcellname, C_IN, dnstype, answer, sizeof(answer));
+#else
     LOCK_GLOBAL_MUTEX;
     len = res_search(dotcellname, C_IN, dnstype, answer, sizeof(answer));
     UNLOCK_GLOBAL_MUTEX;
+#endif
 
     if (len < 0) {
 	if (try_init < 1) {
