$NetBSD: patch-gnulib-lib-base64.h,v 1.1 2014/01/25 02:54:27 agc Exp $

Avoid native header definitions

--- gnulib/lib/base64.h.orig	2014-01-07 19:14:57.000000000 -0800
+++ gnulib/lib/base64.h	2014-01-24 18:03:33.000000000 -0800
@@ -15,8 +15,8 @@
    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, see <http://www.gnu.org/licenses/>.  */
 
-#ifndef BASE64_H
-# define BASE64_H
+#ifndef GNULIB_LIB_BASE64_H
+# define GNULIB_LIB_BASE64_H
 
 /* Get size_t. */
 # include <stddef.h>
@@ -65,4 +65,4 @@
 }
 # endif
 
-#endif /* BASE64_H */
+#endif /* GNULIB_LIB_BASE64_H */
