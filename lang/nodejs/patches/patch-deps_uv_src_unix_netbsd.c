$NetBSD: patch-deps_uv_src_unix_netbsd.c,v 1.10 2019/05/31 20:52:00 adam Exp $

Bring back support for NetBSD<8.

--- deps/uv/src/unix/netbsd.c.orig	2019-05-28 21:32:17.000000000 +0000
+++ deps/uv/src/unix/netbsd.c
@@ -32,6 +32,7 @@
 #include <stdlib.h>
 #include <fcntl.h>
 
+#include <sys/param.h>
 #include <sys/resource.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
@@ -78,7 +79,11 @@ int uv_exepath(char* buffer, size_t* siz
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
