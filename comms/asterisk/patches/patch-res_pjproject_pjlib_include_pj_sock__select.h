$NetBSD: patch-res_pjproject_pjlib_include_pj_sock__select.h,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- res/pjproject/pjlib/include/pj/sock_select.h.orig	2015-10-09 22:23:39.000000000 +0000
+++ res/pjproject/pjlib/include/pj/sock_select.h
@@ -25,6 +25,7 @@
  * @brief Socket select().
  */
 
+#include <limits.h>
 #include <pj/types.h>
 
 PJ_BEGIN_DECL 
@@ -55,7 +56,7 @@ PJ_BEGIN_DECL 
  */
 typedef struct pj_fd_set_t
 {
-    pj_sock_t data[PJ_IOQUEUE_MAX_HANDLES+ 4]; /**< Opaque buffer for fd_set */
+    pj_sock_t data[PJ_IOQUEUE_MAX_HANDLES / sizeof(pj_sock_t) / CHAR_BIT + 4]; /**< Opaque buffer for fd_set */
 } pj_fd_set_t;
 
 
