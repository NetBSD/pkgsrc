$NetBSD: patch-src_Utils.cpp,v 1.1 2017/06/15 14:54:45 fhajny Exp $

d_type is not POSIX, provide workaround for SunOS.

--- src/Utils.cpp.orig	2016-06-27 19:31:18.000000000 +0000
+++ src/Utils.cpp
@@ -23,6 +23,9 @@
 
 #include <curl/curl.h>
 #include <string.h>
+#ifdef __sun
+struct stat s;
+#endif
 
 // A simple struct for strings.
 typedef struct {
@@ -1232,7 +1235,12 @@ bool scan_dir(const char * dir_name, lis
     entry = readdir (d);
     if(!entry) break;
     d_name = entry->d_name;
+#ifdef __sun
+    stat(entry->d_name, &s);
+    if (!(s.st_mode & S_IFDIR)) {
+#else
     if(!(entry->d_type & DT_DIR)) {
+#endif
       if(!stat(entry->d_name, &file_stats)) {
         struct dirent *temp = (struct dirent *)malloc(sizeof(struct dirent));
         memcpy(temp, entry, sizeof(struct dirent));
@@ -1241,7 +1249,12 @@ bool scan_dir(const char * dir_name, lis
       }
     }
 
+#ifdef __sun
+    stat(entry->d_name, &s);
+    if (s.st_mode & S_IFDIR) {
+#else
     if(entry->d_type & DT_DIR) {
+#endif
       if(strncmp (d_name, "..", 2) != 0 &&
           strncmp (d_name, ".", 1) != 0) {
         int path_length;
