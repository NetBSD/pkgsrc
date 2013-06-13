$NetBSD: patch-deps_uv_src_unix_netbsd.c,v 1.2 2013/06/13 20:11:05 fhajny Exp $

Fix build on NetBSD-current.
--- deps/uv/src/unix/netbsd.c-orig      2013-06-05 12:34:12.000000000 +0000
+++ deps/uv/src/unix/netbsd.c
@@ -37,6 +37,7 @@
 #include <sys/resource.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <uvm/uvm.h>
 
 #include <unistd.h>
 #include <time.h>
