$NetBSD: patch-roms_qemu-palcode_printf.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

- Include local header file for prototypes.
- Add puts(), which the compiler may emit a call to if the string passed
  to printf has no format specifiers.

--- roms/qemu-palcode/printf.c.orig	2020-10-04 17:01:51.396706889 +0000
+++ roms/qemu-palcode/printf.c	2020-10-04 17:02:27.588036847 +0000
@@ -18,10 +18,8 @@
    along with this program; see the file COPYING.  If not see
    <http://www.gnu.org/licenses/>.  */
 
-#include <stdarg.h>
-#include <stdbool.h>
-#include <string.h>
 #include "console.h"
+#include "protos.h"
 
 static int print_buf_pad(char *buf, int buflen, char *p, int width, int pad)
 {
@@ -201,3 +199,10 @@ int printf(const char *fmt, ...)
   va_end(args);
   return r;
 }
+
+int puts(const char *s)
+{
+  int len = strlen(s);
+  crb_puts(0, s, len);
+  return len;
+}
