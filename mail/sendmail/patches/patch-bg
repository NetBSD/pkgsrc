$NetBSD: patch-bg,v 1.2 2021/07/04 07:57:13 jnemeth Exp $

--- include/sm/config.h.orig	2020-05-19 19:54:32.000000000 +0000
+++ include/sm/config.h
@@ -29,7 +29,7 @@
 */
 
 # ifndef SM_CONF_STDBOOL_H
-#  if !defined(__clang__) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
+#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
 #   define SM_CONF_STDBOOL_H		1
 #  else
 #   define SM_CONF_STDBOOL_H		0
