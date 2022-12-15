$NetBSD: patch-frm_frm.h,v 1.1 2022/12/15 13:58:02 vins Exp $

Define MB_LEN_MAX.

--- frm/frm.h.orig	2022-02-12 15:20:43.000000000 +0000
+++ frm/frm.h
@@ -33,6 +33,9 @@
 #ifdef HAVE_ICONV_H
 # include <iconv.h>
 #endif
+#ifdef HAVE_LIMITS_H
+# include <limits.h>
+#endif
 #ifndef MB_LEN_MAX
 # define MB_LEN_MAX 4
 #endif
