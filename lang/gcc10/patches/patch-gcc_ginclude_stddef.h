$NetBSD: patch-gcc_ginclude_stddef.h,v 1.1 2024/04/01 18:08:48 js Exp $

Include the system <stddef.h> first, as otherwise we'll end up without
ptrdiff_t and size_t depending on include order.

--- gcc/ginclude/stddef.h.orig	2023-07-07 07:08:19.000000000 +0000
+++ gcc/ginclude/stddef.h
@@ -21,6 +21,10 @@ a copy of the GCC Runtime Library Except
 see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
 <http://www.gnu.org/licenses/>.  */
 
+#ifdef __QNX__
+# include_next <stddef.h>
+#endif
+
 /*
  * ISO C Standard:  7.17  Common definitions  <stddef.h>
  */
