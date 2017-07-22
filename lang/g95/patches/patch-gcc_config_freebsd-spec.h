$NetBSD: patch-gcc_config_freebsd-spec.h,v 1.4 2017/07/22 18:05:43 maya Exp $

Do not create duplicate definitions.
Add support for FreeBSD 9 to 12
From FreeBSD ports.

--- ../gcc-4.1.2/gcc/config/freebsd-spec.h.orig	2005-07-19 13:42:12.000000000 +0000
+++ ../gcc-4.1.2/gcc/config/freebsd-spec.h
@@ -51,11 +51,17 @@ Boston, MA 02110-1301, USA.  */
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 9)						\
+	if (FBSD_MAJOR == 12)						\
+	  builtin_define ("__FreeBSD__=12");				\
+	else if (FBSD_MAJOR == 11)					\
+	  builtin_define ("__FreeBSD__=11");				\
+	else if (FBSD_MAJOR == 10)					\
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
