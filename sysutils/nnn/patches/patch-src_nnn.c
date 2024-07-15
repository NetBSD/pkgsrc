$NetBSD: patch-src_nnn.c,v 1.7 2024/07/15 22:44:54 sjmulder Exp $

 - dprintf() polyfill for Solaris.
   https://github.com/jarun/nnn/pull/1911
 - Disable large file support on old glibc where unsupported in fts.h.
   https://github.com/jarun/nnn/pull/1910

--- src/nnn.c.orig	2023-08-27 04:25:13.000000000 +0000
+++ src/nnn.c
@@ -28,13 +28,16 @@
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#define _FILE_OFFSET_BITS 64 /* Support large files on 32-bit glibc */
-
 #if defined(__linux__) || defined(MINGW) || defined(__MINGW32__) \
 	|| defined(__MINGW64__) || defined(__CYGWIN__)
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif
+#include <features.h>		/* __GLIBC__ etc */
+/* large file support on 32-bit glibc >= 2.23 where fts.h supports it */
+#if !defined(__GLIBC__) || __GLIBC__ > 2 || __GLIBC_MINOR__ >= 23
+#define _FILE_OFFSET_BITS 64
+#endif
 #if defined(__linux__)
 #include <sys/inotify.h>
 #define LINUX_INOTIFY
@@ -121,6 +124,10 @@
 #define alloca(size) __builtin_alloca(size)
 #endif
 
+#ifdef __sun
+#define NEED_DPRINTF
+#endif
+
 #include "nnn.h"
 #include "dbg.h"
 
@@ -854,6 +861,27 @@ static void notify_fifo(bool force);
 
 /* Functions */
 
+#ifdef NEED_DPRINTF
+static int dprintf(int fd, const char *format, ...)
+{
+	va_list ap;
+	char *s;
+	int len, nwritten;
+
+	va_start(ap, format);
+	len = vasprintf(&s, format, ap);
+	va_end(ap);
+
+	if (len == -1)
+		return -1;
+
+	nwritten = write(fd, s, len);
+	free(s);
+
+	return nwritten;
+}
+#endif
+
 static void sigint_handler(int sig)
 {
 	(void) sig;
