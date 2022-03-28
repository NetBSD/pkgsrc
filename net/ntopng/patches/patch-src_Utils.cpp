$NetBSD: patch-src_Utils.cpp,v 1.6 2022/03/28 19:32:25 adam Exp $

Fix building on NetBSD.
d_type is not POSIX, provide workaround for SunOS.

--- src/Utils.cpp.orig	2022-02-02 17:01:08.000000000 +0000
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
@@ -2402,7 +2405,12 @@ static bool scan_dir(const char * dir_na
     if(!entry) break;
     d_name = entry->d_name;
 
+#ifdef __sun
+    stat(entry->d_name, &s);
+    if (s.st_mode & S_IFREG) {
+#else
     if(entry->d_type & DT_REG) {
+#endif
       snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
       if(!stat(path, &buf)) {
         struct dirent *temp = (struct dirent *)malloc(sizeof(struct dirent));
@@ -2412,7 +2420,11 @@ static bool scan_dir(const char * dir_na
 	  *total += buf.st_size;
       }
 
+#ifdef __sun
+    } else if (s.st_mode & S_IFDIR) {
+#else
     } else if(entry->d_type & DT_DIR) {
+#endif
       if(strncmp (d_name, "..", 2) != 0 &&
 	 strncmp (d_name, ".", 1) != 0) {
         path_length = snprintf (path, MAX_PATH,
