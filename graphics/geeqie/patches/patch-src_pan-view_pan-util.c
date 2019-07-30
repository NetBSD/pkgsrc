$NetBSD: patch-src_pan-view_pan-util.c,v 1.1 2019/07/30 13:03:18 ryoon Exp $

* __GLIBC_PREREQ is not universal.

--- src/pan-view/pan-util.c.orig	2019-07-26 18:19:11.000000000 +0000
+++ src/pan-view/pan-util.c
@@ -99,8 +99,12 @@ gchar *pan_date_value_string(time_t d, P
 			format = "%A %e";
 			break;
 		case PAN_DATE_LENGTH_MONTH:
-#if __GLIBC_PREREQ(2, 27)
+#if defined(__GLIBC_PREREQ)
+#  if __GLIBC_PREREQ(2, 27)
 			format = "%OB %Y";
+#  else
+			format = "%B %Y";
+#  endif
 #else
 			format = "%B %Y";
 #endif
