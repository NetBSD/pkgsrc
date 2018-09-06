$NetBSD: patch-lib_ipmi__main.c,v 1.1 2018/09/06 09:47:02 jperkin Exp $

Avoid defines that result in getpass() failures on Darwin.

--- lib/ipmi_main.c.orig	2016-07-31 06:56:33.000000000 +0000
+++ lib/ipmi_main.c
@@ -29,11 +29,13 @@
  * LIABILITY, ARISING OUT OF THE USE OF OR INABILITY TO USE THIS SOFTWARE,
  * EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
  */
+#if !defined(__APPLE__)
 #define _XOPEN_SOURCE 700
 #define _BSD_SOURCE || \
 	(_XOPEN_SOURCE >= 500 || \
 	_XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED) && \
 	!(_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600)
+#endif
 
 #include <stdlib.h>
 #include <stdio.h>
