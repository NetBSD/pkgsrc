$NetBSD: patch-include_m__string.h,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- include/m_string.h.orig	2021-09-14 09:08:08.000000000 +0000
+++ include/m_string.h
@@ -28,11 +28,13 @@
 
 #include <string.h>
 
+#if 0  /* pkgsrc */
 #define bfill please_use_memset_rather_than_bfill
 #ifdef bzero
 #undef bzero
 #endif
 #define bzero please_use_memset_rather_than_bzero
+#endif
 #define bmove please_use_memmove_rather_than_bmove
 #define strmov please_use_my_stpcpy_or_my_stpmov_rather_than_strmov
 #define strnmov please_use_my_stpncpy_or_my_stpnmov_rather_than_strnmov
