$NetBSD: patch-deps_uv_src_unix_netbsd.c,v 1.1 2017/11/01 12:07:31 fhajny Exp $

Bring back support for NetBSD<8.

--- deps/uv/src/unix/netbsd.c.orig	2017-10-24 19:40:12.000000000 +0000
+++ deps/uv/src/unix/netbsd.c
@@ -40,6 +40,11 @@
 #include <unistd.h>
 #include <time.h>
 
+/* For __NetBSD_Version__ */
+#ifdef __NetBSD__
+# include <sys/param.h>
+#endif
+
 static char *process_title;
 
 
@@ -80,7 +85,11 @@ int uv_exepath(char* buffer, size_t* siz
   mib[0] = CTL_KERN;
   mib[1] = KERN_PROC_ARGS;
   mib[2] = -1;
+#if __NetBSD_Version__ >= 799000000
   mib[3] = KERN_PROC_PATHNAME;
+#else
+  mib[3] = KERN_PROC_ARGV;
+#endif
   int_size = ARRAY_SIZE(int_buf);
 
   if (sysctl(mib, 4, int_buf, &int_size, NULL, 0))
