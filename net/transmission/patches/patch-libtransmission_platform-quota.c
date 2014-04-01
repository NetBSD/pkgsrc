$NetBSD: patch-libtransmission_platform-quota.c,v 1.2 2014/04/01 11:13:28 wiz Exp $

Quota support for NetBSD-6+.
http://trac.transmissionbt.com/ticket/5643

--- libtransmission/platform-quota.c.orig	2013-08-09 02:45:44.000000000 +0000
+++ libtransmission/platform-quota.c
@@ -20,6 +20,11 @@
  #include <sys/types.h> /* types needed by quota.h */
  #if defined(__FreeBSD__) || defined(__OpenBSD__)
   #include <ufs/ufs/quota.h> /* quotactl() */
+ #elif defined (__NetBSD__)
+  #include <sys/param.h>
+  #ifndef statfs
+   #define statfs statvfs
+  #endif
  #elif defined (__sun)
   #include <sys/fs/ufs_quota.h> /* quotactl */
  #else
@@ -195,6 +200,47 @@ getblkdev (const char * path)
   return device;
 }
 
+#if defined(__NetBSD__) && (__NetBSD_Version__ >= 600000000)
+#include <quota.h>
+
+static int64_t
+getquota (const char * device)
+{
+  struct quotahandle *qh;
+  struct quotakey qk;
+  struct quotaval qv;
+  int64_t limit;
+  int64_t freespace;
+  int64_t spaceused;
+
+  qh = quota_open(device);
+  if (qh == NULL) {
+    return -1;
+  }
+  qk.qk_idtype = QUOTA_IDTYPE_USER;
+  qk.qk_id = getuid();
+  qk.qk_objtype = QUOTA_OBJTYPE_BLOCKS;
+  if (quota_get(qh, &qk, &qv) == -1) {
+    quota_close(qh);
+    return -1;
+  }
+  if (qv.qv_softlimit > 0) {
+    limit = qv.qv_softlimit;
+  }
+  else if (qv.qv_hardlimit > 0) {
+    limit = qv.qv_hardlimit;
+  }
+  else {
+    quota_close(qh);
+    return -1;
+  }
+  spaceused = qv.qv_usage;
+  quota_close(qh);
+
+  freespace = limit - spaceused;
+  return (freespace < 0) ? 0 : freespace;
+}
+#else
 static int64_t
 getquota (const char * device)
 {
@@ -259,6 +305,7 @@ getquota (const char * device)
   /* something went wrong */
   return -1;
 }
+#endif
 
 #ifdef HAVE_XQM
 static int64_t
