$NetBSD: patch-crypto__bio__socket_helper.c,v 1.1.1.1 2015/12/31 02:57:35 agc Exp $

NetBSD portability patches

--- crypto/bio/socket_helper.c.orig	2015-12-30 15:55:50.000000000 -0800
+++ crypto/bio/socket_helper.c	2015-12-30 18:06:05.000000000 -0800
@@ -12,8 +12,10 @@
  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
 
+#if !defined(__NetBSD__)
 #undef _POSIX_C_SOURCE
 #define _POSIX_C_SOURCE 200112L
+#endif
 
 #include <openssl/bio.h>
 #include <openssl/err.h>
