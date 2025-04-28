$NetBSD: patch-idev.c,v 1.1 2025/04/28 11:38:37 hauke Exp $

Do not use ssp(3) when compiling idev.c:


In file included from mbconf.h:23,
                 from idev.c:20:
config.h:78:19: error: redefinition of 'read'
   78 | #define LIBC_READ read
      |                   ^~~~
idev.c:90:9: note: in expansion of macro 'LIBC_READ'
   90 | ssize_t LIBC_READ(int fd, void *buf, size_t s)
      |         ^~~~~~~~~
In file included from /usr/include/ssp/unistd.h:34,
                 from /usr/include/unistd.h:74,
                 from mbconf.h:41,
                 from idev.c:20:
/usr/include/ssp/unistd.h:39:1: note: previous definition of 'read' was here
   39 | __ssp_redirect0(ssize_t, read, (int __fd, void *__buf, size_t __len), \
      | ^~~~~~~~~~~~~~~

--- idev.c.orig	2025-04-28 09:10:06.810889379 +0000
+++ idev.c
@@ -17,6 +17,8 @@
  *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#undef _FORTIFY_SOURCE
+
 #include "mbconf.h"
 #include <assert.h>
 #include <dlfcn.h>
