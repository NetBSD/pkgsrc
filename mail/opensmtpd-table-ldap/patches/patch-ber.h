$NetBSD: patch-ber.h,v 1.1 2025/03/10 07:57:40 vins Exp $

Portability fix for pkgsrc.

--- ber.h.orig	2025-03-10 07:42:21.524815621 +0000
+++ ber.h
@@ -15,6 +15,13 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>	/* __BEGIN_DECLS */
+#else
+#include <sys/cdefs.h>
+#endif
+
 struct ber_element {
 	struct ber_element	*be_next;
 	unsigned long		 be_type;
