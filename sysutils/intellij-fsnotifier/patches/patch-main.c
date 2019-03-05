$NetBSD: patch-main.c,v 1.1 2019/03/05 11:24:01 ryoon Exp $

* Fix build on NetBSD

--- main.c.orig	2016-11-18 15:38:37.000000000 +0000
+++ main.c
@@ -429,17 +429,31 @@ static bool register_roots(array* new_ro
 #if defined(__BSD__)
 
 static array* unwatchable_mounts() {
+#if defined(__NetBSD__)
+  int fsCount = getvfsstat(NULL, 0, MNT_WAIT);
+#else
   int fsCount = getfsstat(NULL, 0, MNT_WAIT);
+#endif
   if (fsCount > 0) {
+#if defined(__NetBSD__)
+    struct statvfs fs[fsCount];
+    fsCount = getvfsstat(fs, (int)(sizeof(struct statvfs) * fsCount), MNT_NOWAIT);
+#else
     struct statfs fs[fsCount];
     fsCount = getfsstat(fs, (int)(sizeof(struct statfs) * fsCount), MNT_NOWAIT);
+#endif
     if (fsCount > 0) {
       array* mounts = array_create(fsCount);
       CHECK_NULL(mounts, NULL);
 
       for (int i=0; i<fsCount; i++) {
+#if defined(__NetBSD__)
+        userlog(LOG_DEBUG, "mtab: %s : %s (%d)", fs[i].f_mntonname, fs[i].f_fstypename, fs[i].f_flag);
+        if ((fs[i].f_flag & MNT_LOCAL) != MNT_LOCAL) {
+#else
         userlog(LOG_DEBUG, "mtab: %s : %s (%d)", fs[i].f_mntonname, fs[i].f_fstypename, fs[i].f_flags);
         if ((fs[i].f_flags & MNT_LOCAL) != MNT_LOCAL) {
+#endif
           CHECK_NULL(array_push(mounts, strdup(fs[i].f_mntonname)), NULL);
         }
       }
@@ -512,8 +526,14 @@ static void inotify_callback(const char*
 static void report_event(const char* event, const char* path) {
   userlog(LOG_DEBUG, "%s: %s", event, path);
 
+#if defined(__clang__)
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wincompatible-pointer-types"
+#elif defined(__GNUC__)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
+#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
+#endif
   char* copy = path, *p;
   for (p = copy; *p != '\0'; ++p) {
     if (*p == '\n') {
@@ -524,7 +544,11 @@ static void report_event(const char* eve
       *p = '\0';
     }
   }
+#if defined(__clang__)
 #pragma clang diagnostic pop
+#elif defined(__GNUC__)
+#pragma GCC diagnostic pop
+#endif
 
   fputs(event, stdout);
   fputc('\n', stdout);
