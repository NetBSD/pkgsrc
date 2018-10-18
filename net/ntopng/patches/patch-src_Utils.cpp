$NetBSD: patch-src_Utils.cpp,v 1.2 2018/10/18 16:25:40 adam Exp $

Fix building on NetBSD.
d_type is not POSIX, provide workaround for SunOS.

--- src/Utils.cpp.orig	2018-09-19 15:35:27.000000000 +0000
+++ src/Utils.cpp
@@ -21,10 +21,13 @@
 
 #include "ntop_includes.h"
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
 #include <net/if_dl.h>
 #include <ifaddrs.h>
 #endif
+#ifdef __sun
+struct stat s;
+#endif
 
 // A simple struct for strings.
 typedef struct {
@@ -1747,7 +1750,12 @@ static bool scan_dir(const char * dir_na
     if(!entry) break;
     d_name = entry->d_name;
 
+#ifdef __sun
+    stat(entry->d_name, &s);
+    if (s.st_mode & S_IFREG) {
+#else
     if(entry->d_type & DT_REG) {
+#endif
       snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
       if(!stat(path, &file_stats)) {
         struct dirent *temp = (struct dirent *)malloc(sizeof(struct dirent));
@@ -1757,7 +1765,11 @@ static bool scan_dir(const char * dir_na
 	  *total += file_stats.st_size;
       }
 
+#ifdef __sun
+    } else if (s.st_mode & S_IFDIR) {
+#else
     } else if(entry->d_type & DT_DIR) {
+#endif
       if(strncmp (d_name, "..", 2) != 0 &&
           strncmp (d_name, ".", 1) != 0) {
         path_length = snprintf (path, MAX_PATH,
@@ -1849,7 +1861,12 @@ bool ntop_delete_old_files(const char *d
   if(!d) return false;
 
   while((result = readdir(d)) != NULL) {
+#ifdef __sun
+    stat(entry->d_name, &s);
+    if (s.st_mode & S_IFREG) {
+#else
     if(result->d_type & DT_REG) {
+#endif
       if((path_length = snprintf(path, MAX_PATH, "%s/%s", dir_name, result->d_name)) <= MAX_PATH) {
 	ntop->fixPath(path);
 
@@ -1858,7 +1875,11 @@ bool ntop_delete_old_files(const char *d
 	    unlink(path);
 	}
       }
+#ifdef __sun
+    } else if (s.st_mode & S_IFDIR) {
+#else
     } else if(result->d_type & DT_DIR) {
+#endif
       if(strncmp(result->d_name, "..", 2) && strncmp(result->d_name, ".", 1)) {
         if((path_length = snprintf(path, MAX_PATH, "%s/%s", dir_name, result->d_name)) <= MAX_PATH) {
 	  ntop->fixPath(path);
