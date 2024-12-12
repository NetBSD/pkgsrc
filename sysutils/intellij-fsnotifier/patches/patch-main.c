$NetBSD: patch-main.c,v 1.2 2024/12/12 15:21:57 ryoon Exp $

* Fix build on NetBSD

--- main.c.orig	2023-07-24 21:16:54.000000000 +0000
+++ main.c
@@ -10,7 +10,11 @@
 #include <string.h>
 #include <sys/inotify.h>
 #include <sys/select.h>
+#if !defined(__NetBSD__)
 #include <sys/stat.h>
+#else
+#include <sys/statvfs.h>
+#endif
 #include <unistd.h>
 
 #if defined(__BSD__)
@@ -316,17 +320,29 @@ static bool register_roots(array* new_ro
 
 #if defined(__BSD__)
 static array* unwatchable_mounts(void) {
+# if !defined(__NetBSD__)
   int fsCount = getfsstat(NULL, 0, MNT_WAIT);
   if (fsCount > 0) {
     struct statfs fs[fsCount];
     fsCount = getfsstat(fs, (int)(sizeof(struct statfs) * fsCount), MNT_NOWAIT);
+#else
+  int fsCount = getvfsstat(NULL, 0, MNT_WAIT);
+  if (fsCount > 0) {
+    struct statvfs fs[fsCount];
+    fsCount = getvfsstat(fs, (int)(sizeof(struct statvfs) * fsCount), MNT_NOWAIT);
+#endif
     if (fsCount > 0) {
       array* mounts = array_create(fsCount);
       CHECK_NULL(mounts, NULL);
 
       for (int i=0; i<fsCount; i++) {
+#if !defined(__NetBSD__)
         userlog(LOG_INFO, "mtab: %s : %s (%d)", fs[i].f_mntonname, fs[i].f_fstypename, fs[i].f_flags);
         if ((fs[i].f_flags & MNT_LOCAL) != MNT_LOCAL) {
+#else
+        userlog(LOG_INFO, "mtab: %s : %s (%d)", fs[i].f_mntonname, fs[i].f_fstypename, fs[i].f_flag);
+        if ((fs[i].f_flag & MNT_LOCAL) != MNT_LOCAL) {
+#endif
           CHECK_NULL(array_push(mounts, strdup(fs[i].f_mntonname)), NULL);
         }
       }
