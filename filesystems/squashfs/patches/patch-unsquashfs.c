$NetBSD: patch-unsquashfs.c,v 1.1 2016/09/09 15:40:17 scole Exp $
Some workarounds for not using autoconf and include fnm_extmatch.h

--- unsquashfs.c.orig	2014-05-12 22:18:35.000000000 +0000
+++ unsquashfs.c
@@ -31,13 +31,25 @@
 #include "unsquashfs_info.h"
 #include "stdarg.h"
 
-#include <sys/sysinfo.h>
+/* XXX need autoconf */
+#if ( defined(__linux__) )
+ #include <sys/sysinfo.h>
+#endif
+
+/* XXX need autoconf HAVE_SYS_SYSCTL_H */
+#if ( defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__) || \
+      defined(__FreeBSD__) || defined(__OpenBSD__) )
+ #include <sys/sysctl.h>
+#endif
+
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <limits.h>
 #include <ctype.h>
 
+#include "fnm_extmatch.h"
+
 struct cache *fragment_cache, *data_cache;
 struct queue *to_reader, *to_inflate, *to_writer, *from_writer;
 pthread_t *thread, *inflator_thread;
