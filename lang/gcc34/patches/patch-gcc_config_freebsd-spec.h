$NetBSD: patch-gcc_config_freebsd-spec.h,v 1.1 2014/07/02 22:10:40 asau Exp $

--- gcc/config/freebsd-spec.h.orig	2005-07-19 21:08:48.000000000 +0000
+++ gcc/config/freebsd-spec.h
@@ -51,11 +51,13 @@ Boston, MA 02111-1307, USA.  */
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 9)						\
+	if (FBSD_MAJOR == 10)						\
+	  builtin_define ("__FreeBSD__=10");			       	\
+	else if (FBSD_MAJOR == 9)					\
 	  builtin_define ("__FreeBSD__=9");			       	\
 	else if (FBSD_MAJOR == 8)					\
 	  builtin_define ("__FreeBSD__=8");			       	\
-	if (FBSD_MAJOR == 7)						\
+	else if (FBSD_MAJOR == 7)					\
 	  builtin_define ("__FreeBSD__=7");			       	\
 	else if (FBSD_MAJOR == 6)					\
 	  builtin_define ("__FreeBSD__=6");			       	\
