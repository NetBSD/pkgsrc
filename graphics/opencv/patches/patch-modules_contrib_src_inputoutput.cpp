$NetBSD: patch-modules_contrib_src_inputoutput.cpp,v 1.1 2013/06/12 10:13:58 jperkin Exp $

SunOS does not have dirent d_type.

--- modules/contrib/src/inputoutput.cpp.orig	2012-10-17 22:55:38.000000000 +0000
+++ modules/contrib/src/inputoutput.cpp
@@ -5,6 +5,9 @@
     #include <windows.h>
     #include <tchar.h>
 #else
+#ifdef __sun
+    #include <sys/stat.h>
+#endif
     #include <dirent.h>
 #endif
 
@@ -47,6 +50,10 @@ namespace cv
             (void)addPath;
             DIR *dp;
             struct dirent *dirp;
+#ifdef __sun
+            struct stat sb;
+            char buf[PATH_MAX];
+#endif
             if((dp = opendir(path.c_str())) == NULL)
             {
                 return list;
@@ -54,7 +61,13 @@ namespace cv
 
             while ((dirp = readdir(dp)) != NULL)
             {
+#ifdef __sun
+                snprintf(buf, PATH_MAX, "%s/%s", path.c_str(), dirp->d_name);
+                stat(buf, &sb);
+                if (S_ISREG(sb.st_mode))
+#else
                 if (dirp->d_type == DT_REG)
+#endif
                 {
                     if (exten.compare("*") == 0)
                         list.push_back(static_cast<std::string>(dirp->d_name));
@@ -105,6 +118,10 @@ namespace cv
             (void)addPath;
             DIR *dp;
             struct dirent *dirp;
+#ifdef __sun
+            struct stat sb;
+            char buf[PATH_MAX];
+#endif
             if((dp = opendir(path_f.c_str())) == NULL)
             {
                 return list;
@@ -112,7 +129,13 @@ namespace cv
 
             while ((dirp = readdir(dp)) != NULL)
             {
+#ifdef __sun
+                snprintf(buf, PATH_MAX, "%s/%s", path.c_str(), dirp->d_name);
+                stat(buf, &sb);
+                if (S_ISDIR(sb.st_mode) &&
+#else
                 if (dirp->d_type == DT_DIR &&
+#endif
                     strcmp(dirp->d_name, ".") != 0 &&
                     strcmp(dirp->d_name, "..") != 0 )
                 {
