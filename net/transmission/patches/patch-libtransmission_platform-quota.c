$NetBSD$

Fix dragonflybsd build

--- libtransmission/platform-quota.c.orig	2017-06-19 12:56:41.129003307 +0000
+++ libtransmission/platform-quota.c
@@ -18,6 +18,8 @@
  #include <sys/types.h> /* types needed by quota.h */
  #if defined(__FreeBSD__) || defined(__OpenBSD__)
   #include <ufs/ufs/quota.h> /* quotactl() */
+ #elif defined (__DragonFly__)
+  #include <vfs/ufs/quota.h> /* quotactl */
  #elif defined (__NetBSD__)
   #include <sys/param.h>
   #ifndef statfs
@@ -244,12 +246,16 @@ getquota (const char * device)
 static int64_t
 getquota (const char * device)
 {
+#ifdef __DragonFly__
+  struct ufs_dqblk dq;
+#else
   struct dqblk dq;
+#endif
   int64_t limit;
   int64_t freespace;
   int64_t spaceused;
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__APPLE__)
   if (quotactl(device, QCMD(Q_GETQUOTA, USRQUOTA), getuid(), (caddr_t) &dq) == 0)
     {
 #elif defined(__sun)
@@ -281,7 +287,7 @@ getquota (const char * device)
           /* No quota enabled for this user */
           return -1;
         }
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
       spaceused = (int64_t) dq.dqb_curblocks >> 1;
 #elif defined(__APPLE__)
       spaceused = (int64_t) dq.dqb_curbytes;
