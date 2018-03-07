$NetBSD: patch-deps_uv_src_unix_netbsd.c,v 1.2 2018/03/07 11:45:06 fhajny Exp $

Bring back support for NetBSD<8.

--- deps/uv/src/unix/netbsd.c.orig	2018-03-06 22:55:45.000000000 +0000
+++ deps/uv/src/unix/netbsd.c
@@ -40,6 +40,11 @@
 #include <unistd.h>
 #include <time.h>
 
+/* For __NetBSD_Version__ */
+#ifdef __NetBSD__
+# include <sys/param.h>
+#endif
+
 static uv_mutex_t process_title_mutex;
 static uv_once_t process_title_mutex_once = UV_ONCE_INIT;
 static char *process_title;
@@ -87,7 +92,11 @@ int uv_exepath(char* buffer, size_t* siz
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
