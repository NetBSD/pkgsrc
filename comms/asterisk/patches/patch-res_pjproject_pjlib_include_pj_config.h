$NetBSD: patch-res_pjproject_pjlib_include_pj_config.h,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- res/pjproject/pjlib/include/pj/config.h.orig	2015-10-09 22:23:39.000000000 +0000
+++ res/pjproject/pjlib/include/pj/config.h
@@ -555,7 +555,7 @@
  * the underlying implementation changes.
  */
 #ifndef PJ_IOQUEUE_MAX_HANDLES
-#   define PJ_IOQUEUE_MAX_HANDLES	(64)
+#   define PJ_IOQUEUE_MAX_HANDLES	(1024)
 #endif
 
 
@@ -622,16 +622,10 @@
 
 /**
  * Determine if FD_SETSIZE is changeable/set-able. If so, then we will
- * set it to PJ_IOQUEUE_MAX_HANDLES. Currently we detect this by checking
- * for Winsock.
+ * set it to PJ_IOQUEUE_MAX_HANDLES. Assumed to be supported by default.
  */
 #ifndef PJ_FD_SETSIZE_SETABLE
-#   if (defined(PJ_HAS_WINSOCK_H) && PJ_HAS_WINSOCK_H!=0) || \
-       (defined(PJ_HAS_WINSOCK2_H) && PJ_HAS_WINSOCK2_H!=0)
-#	define PJ_FD_SETSIZE_SETABLE	1
-#   else
-#	define PJ_FD_SETSIZE_SETABLE	0
-#   endif
+#   define PJ_FD_SETSIZE_SETABLE	1
 #endif
 
 /**
