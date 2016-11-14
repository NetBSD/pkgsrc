--- external/libfetch/http.c.orig	2016-02-10 23:09:08 UTC
+++ external/libfetch/http.c
@@ -60,6 +60,9 @@
  * SUCH DAMAGE.
  */
 #define _XOPEN_SOURCE
+#ifdef __NetBSD__
+#define _NETBSD_SOURCE
+#endif
 #include <sys/param.h>
 #include <sys/socket.h>
 #include <sys/time.h>
