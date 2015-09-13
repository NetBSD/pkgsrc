$NetBSD: patch-src_af_util_xp_ut__iconv.h,v 1.1 2015/09/13 21:32:13 nros Exp $

--- src/af/util/xp/ut_iconv.h.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/util/xp/ut_iconv.h
@@ -30,8 +30,14 @@
 #include "ut_types.h"
 #endif
 
+#include <sys/param.h>
+
 typedef void * UT_iconv_t;
 
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 200000000
+struct __tag_iconv_t { }; /* XXX: for catch/throw (ISO C++ 15.1)*/
+#endif
+
 #define UT_ICONV_INVALID ((UT_iconv_t)(-1))
 
 #ifdef __cplusplus
