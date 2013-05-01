$NetBSD: patch-defines.h,v 1.1 2013/05/01 19:58:26 imil Exp $

Define ROOTUID, UTMPX_FILE and WTMPX_FILE

--- defines.h.orig	2013-03-07 09:06:13.000000000 +0000
+++ defines.h
@@ -30,6 +30,15 @@
 
 /* Constants */
 
+#ifdef HAVE_INTERIX
+/* Interix has a special concept of "administrator". */
+# define ROOTUID	197108
+# define ROOTGID	131616
+#else
+# define ROOTUID	0
+# define ROOTGID	0
+#endif
+
 #if defined(HAVE_DECL_SHUT_RD) && HAVE_DECL_SHUT_RD == 0
 enum
 {
@@ -695,6 +704,24 @@ struct winsize {
 #    endif
 #  endif
 #endif
+#ifndef UTMPX_FILE
+#  ifdef _PATH_UTMPX
+#    define UTMPX_FILE _PATH_UTMPX
+#  else
+#    ifdef CONF_UTMPX_FILE
+#      define UTMPX_FILE CONF_UTMPX_FILE
+#    endif
+#  endif
+#endif
+#ifndef WTMPX_FILE
+#  ifdef _PATH_WTMPX
+#    define WTMPX_FILE _PATH_WTMPX
+#  else
+#    ifdef CONF_WTMPX_FILE
+#      define WTMPX_FILE CONF_WTMPX_FILE
+#    endif
+#  endif
+#endif
 /* pick up the user's location for lastlog if given */
 #ifndef LASTLOG_FILE
 #  ifdef _PATH_LASTLOG
