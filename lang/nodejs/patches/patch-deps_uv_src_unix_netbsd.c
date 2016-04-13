$NetBSD: patch-deps_uv_src_unix_netbsd.c,v 1.4 2016/04/13 09:37:35 ryoon Exp $

--- deps/uv/src/unix/netbsd.c.orig	2016-04-05 21:52:30.000000000 +0000
+++ deps/uv/src/unix/netbsd.c
@@ -43,6 +43,11 @@
 #include <unistd.h>
 #include <time.h>
 
+/* For __NetBSD_Version__ */
+#ifdef __NetBSD__
+# include <sys/param.h>
+#endif
+
 #undef NANOSEC
 #define NANOSEC ((uint64_t) 1e9)
 
@@ -90,7 +95,11 @@ int uv_exepath(char* buffer, size_t* siz
   mib[0] = CTL_KERN;
   mib[1] = KERN_PROC_ARGS;
   mib[2] = mypid;
+#if __NetBSD_Version__ >= 799000000
+  mib[3] = KERN_PROC_PATHNAME;
+#else
   mib[3] = KERN_PROC_ARGV;
+#endif
 
   cb = *size;
   if (sysctl(mib, 4, buffer, &cb, NULL, 0))
