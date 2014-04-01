$NetBSD: patch-libtransmission_platform-quota.c,v 1.1 2014/04/01 09:48:04 adam Exp $

Add NetBSD support.

--- libtransmission/platform-quota.c.orig	2014-03-31 18:47:50.000000000 +0000
+++ libtransmission/platform-quota.c
@@ -20,6 +20,8 @@
  #include <sys/types.h> /* types needed by quota.h */
  #if defined(__FreeBSD__) || defined(__OpenBSD__)
   #include <ufs/ufs/quota.h> /* quotactl() */
+ #elif defined(__NetBSD__)
+  #include <ufs/ufs/quota1.h>
  #elif defined (__sun)
   #include <sys/fs/ufs_quota.h> /* quotactl */
  #else
@@ -104,7 +106,11 @@ getdev (const char * path)
 
   int i;
   int n;
+#if defined(__NetBSD__)
+  struct statvfs * mnt;
+#else
   struct statfs * mnt;
+#endif
 
   n = getmntinfo(&mnt, MNT_WAIT);
   if (!n)
@@ -154,7 +160,11 @@ getfstype (const char * device)
 
   int i;
   int n;
+#if defined(__NetBSD__)
+  struct statvfs *mnt;
+#else
   struct statfs *mnt;
+#endif
 
   n = getmntinfo(&mnt, MNT_WAIT);
   if (!n)
@@ -203,7 +213,7 @@ getquota (const char * device)
   int64_t freespace;
   int64_t spaceused;
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(SYS_DARWIN)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(SYS_DARWIN)
   if (quotactl(device, QCMD(Q_GETQUOTA, USRQUOTA), getuid(), (caddr_t) &dq) == 0)
     {
 #elif defined(__sun)
@@ -235,7 +245,7 @@ getquota (const char * device)
           /* No quota enabled for this user */
           return -1;
         }
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
       spaceused = (int64_t) dq.dqb_curblocks >> 1;
 #elif defined(SYS_DARWIN)
       spaceused = (int64_t) dq.dqb_curbytes;
