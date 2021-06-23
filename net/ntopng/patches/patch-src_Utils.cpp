$NetBSD: patch-src_Utils.cpp,v 1.5 2021/06/23 19:34:15 adam Exp $

Fix building on NetBSD.
d_type is not POSIX, provide workaround for SunOS.

--- src/Utils.cpp.orig	2020-11-02 21:27:19.000000000 +0000
+++ src/Utils.cpp
@@ -25,9 +25,12 @@ extern "C" {
 #include "third-party/fast-sha1/sha1-fast.c"
 }
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 #include <net/if_dl.h>
 #endif
+#ifdef __sun
+struct stat s;
+#endif
 
 #ifndef WIN32
 #include <ifaddrs.h>
@@ -2259,7 +2262,12 @@ static bool scan_dir(const char * dir_na
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
@@ -2269,7 +2277,11 @@ static bool scan_dir(const char * dir_na
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
