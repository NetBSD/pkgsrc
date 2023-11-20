$NetBSD: patch-src_Utils.cpp,v 1.7 2023/11/20 17:59:35 adam Exp $

Fix building on NetBSD.
d_type is not POSIX, provide workaround for SunOS.

--- src/Utils.cpp.orig	2023-11-02 14:11:55.000000000 +0000
+++ src/Utils.cpp
@@ -21,9 +21,12 @@
 
 #include "ntop_includes.h"
 
-#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <net/if_dl.h>
 #endif
+#ifdef __sun
+struct stat s;
+#endif
 
 #ifndef WIN32
 #include <ifaddrs.h>
@@ -2605,7 +2608,12 @@ static bool scan_dir(const char *dir_nam
     if (!entry) break;
     d_name = entry->d_name;
 
+#ifdef __sun
+    stat(entry->d_name, &s);
+    if (s.st_mode & S_IFREG) {
+#else
     if (entry->d_type & DT_REG) {
+#endif
       snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
       if (!stat(path, &buf)) {
         struct dirent *temp = (struct dirent *)malloc(sizeof(struct dirent));
@@ -2614,7 +2622,11 @@ static bool scan_dir(const char *dir_nam
         if (total) *total += buf.st_size;
       }
 
+#ifdef __sun
+    } else if (s.st_mode & S_IFDIR) {
+#else
     } else if (entry->d_type & DT_DIR) {
+#endif
       if (strncmp(d_name, "..", 2) != 0 && strncmp(d_name, ".", 1) != 0) {
         path_length = snprintf(path, MAX_PATH, "%s/%s", dir_name, d_name);
 
