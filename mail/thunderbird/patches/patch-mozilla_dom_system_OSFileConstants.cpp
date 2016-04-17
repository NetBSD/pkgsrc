$NetBSD: patch-mozilla_dom_system_OSFileConstants.cpp,v 1.3 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/dom/system/OSFileConstants.cpp.orig	2016-04-07 21:33:31.000000000 +0000
+++ mozilla/dom/system/OSFileConstants.cpp
@@ -11,6 +11,10 @@
 
 #include "prsystem.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #if defined(XP_UNIX)
 #include "unistd.h"
 #include "dirent.h"
@@ -20,7 +24,9 @@
 #define statvfs statfs
 #else
 #include "sys/statvfs.h"
+#if !(defined(__NetBSD__) && (__NetBSD_Version__ < 600000000))
 #include <spawn.h>
+#endif // !NetBSD 5.*
 #endif // defined(ANDROID)
 #endif // defined(XP_UNIX)
 
@@ -28,9 +34,9 @@
 #include <linux/fadvise.h>
 #endif // defined(XP_LINUX)
 
-#if defined(XP_MACOSX)
+#if defined(XP_DARWIN)
 #include "copyfile.h"
-#endif // defined(XP_MACOSX)
+#endif // defined(XP_DARWIN)
 
 #if defined(XP_WIN)
 #include <windows.h>
@@ -590,7 +596,7 @@ static const dom::ConstantSpec gLibcProp
   // The size of |fsblkcnt_t|.
   { "OSFILE_SIZEOF_FSBLKCNT_T", JS::Int32Value(sizeof (fsblkcnt_t)) },
 
-#if !defined(ANDROID)
+#if !defined(ANDROID) && !(defined(__NetBSD__) && (__NetBSD_Version__ < 600000000))
   // The size of |posix_spawn_file_actions_t|.
   { "OSFILE_SIZEOF_POSIX_SPAWN_FILE_ACTIONS_T", JS::Int32Value(sizeof (posix_spawn_file_actions_t)) },
 #endif // !defined(ANDROID)
