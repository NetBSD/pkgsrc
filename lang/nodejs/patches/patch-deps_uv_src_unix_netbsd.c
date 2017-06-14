$NetBSD: patch-deps_uv_src_unix_netbsd.c,v 1.5 2017/06/14 12:59:14 fhajny Exp $

--- deps/uv/src/unix/netbsd.c.orig	2017-06-08 10:31:21.000000000 +0000
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
 
 
@@ -77,7 +82,11 @@ int uv_exepath(char* buffer, size_t* siz
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
