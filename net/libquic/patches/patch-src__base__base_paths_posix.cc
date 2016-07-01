$NetBSD: patch-src__base__base_paths_posix.cc,v 1.1 2016/07/01 20:32:35 agc Exp $

Portability fixes

--- src/base/base_paths_posix.cc	2015/12/30 22:26:32	1.1
+++ src/base/base_paths_posix.cc	2015/12/30 22:28:31
@@ -63,13 +63,13 @@
       }
       *result = FilePath(bin_dir);
       return true;
-#elif defined(OS_OPENBSD)
+#elif defined(OS_OPENBSD) || defined(OS_NETBSD)
       // There is currently no way to get the executable path on OpenBSD
       char* cpath;
       if ((cpath = getenv("CHROME_EXE_PATH")) != NULL)
         *result = FilePath(cpath);
       else
-        *result = FilePath("/usr/local/chrome/chrome");
+        *result = FilePath(@PREFIX@ "/chrome/chrome");
       return true;
 #endif
     }
