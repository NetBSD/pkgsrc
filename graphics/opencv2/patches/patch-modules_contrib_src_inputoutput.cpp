$NetBSD: patch-modules_contrib_src_inputoutput.cpp,v 1.1 2015/10/17 10:28:43 fhajny Exp $

SunOS does not have dirent d_type.

--- modules/contrib/src/inputoutput.cpp.orig	2015-02-25 12:10:31.000000000 +0000
+++ modules/contrib/src/inputoutput.cpp
@@ -6,6 +6,9 @@
     #include <windows.h>
     #include <tchar.h>
 #else
+#ifdef __sun
+    #include <sys/stat.h>
+#endif
     #include <dirent.h>
 #endif
 
@@ -72,6 +75,10 @@ namespace cv
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
@@ -96,6 +103,10 @@ namespace cv
                      extra = _DEXTRA_NEXT(extra),
                      extra_stat = reinterpret_cast<dirent_extra_stat *>(extra))
                 if ((extra->d_type != _DTYPE_NONE) && S_ISREG(extra_stat->d_stat.st_mode))
+            #elif defined(__sun)
+                snprintf(buf, PATH_MAX, "%s/%s", path.c_str(), dirp->d_name);
+                stat(buf, &sb);
+                if (S_ISREG(sb.st_mode))
             #else
                 if (dirp->d_type == DT_REG)
             #endif
@@ -181,6 +192,10 @@ namespace cv
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
@@ -206,6 +221,10 @@ namespace cv
                      extra_stat = reinterpret_cast<dirent_extra_stat *>(extra))
                 if ((extra->d_type != _DTYPE_NONE) &&
                     S_ISDIR(extra_stat->d_stat.st_mode) &&
+            #elif defined(__sun)
+                snprintf(buf, PATH_MAX, "%s/%s", path.c_str(), dirp->d_name);
+                stat(buf, &sb);
+                if (S_ISDIR(sb.st_mode) &&
             #else
                 if (dirp->d_type == DT_DIR &&
             #endif
