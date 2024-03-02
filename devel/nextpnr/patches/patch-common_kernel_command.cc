$NetBSD: patch-common_kernel_command.cc,v 1.2 2024/03/02 23:08:00 thorpej Exp $

On NetBSD, also use KERN_PROC_PATHNAME to get the path to the executable.

--- common/kernel/command.cc.orig	2024-01-23 13:00:29.000000000 +0000
+++ common/kernel/command.cc	2024-03-02 22:33:39.900391210 +0000
@@ -61,7 +61,7 @@
 #include <unistd.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -90,10 +90,14 @@ std::string proc_self_dirname()
         buflen--;
     return std::string(path, buflen);
 }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 std::string proc_self_dirname()
 {
+#ifdef __NetBSD__
+    int mib[4] = {CTL_KERN, KERN_PROC_ARGS, getpid(), KERN_PROC_PATHNAME};
+#else
     int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+#endif
     size_t buflen;
     char *buffer;
     std::string path;
