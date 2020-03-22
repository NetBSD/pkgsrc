$NetBSD: patch-src_file.cc,v 1.2 2020/03/22 10:35:44 nia Exp $

Allow KAK_BIN_PATH to be used as a fallback for finding the executable
path on more platforms.

--- src/file.cc.orig	2020-01-16 09:52:20.000000000 +0000
+++ src/file.cc
@@ -21,7 +21,7 @@
 #include <sys/select.h>
 #include <unistd.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -624,7 +624,7 @@ String get_kak_binary_path()
     kak_assert(res != -1);
     buffer[res] = '\0';
     return buffer;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
     int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
     size_t res = sizeof(buffer);
     sysctl(mib, 4, buffer, &res, NULL, 0);
@@ -648,10 +648,8 @@ String get_kak_binary_path()
     kak_assert(res != -1);
     buffer[res] = '\0';
     return buffer;
-#elif defined(__OpenBSD__)
-    return KAK_BIN_PATH;
 #else
-# error "finding executable path is not implemented on this platform"
+    return KAK_BIN_PATH;
 #endif
 }
 
