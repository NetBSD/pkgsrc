$NetBSD: patch-src_ComUtil_comutil.h,v 1.1 2021/03/01 09:48:40 nia Exp $

Include <sys/types.h> for the use of pid_t in the subsequently included
header.

--- src/ComUtil/comutil.h.orig	2020-10-10 13:03:09.000000000 +0000
+++ src/ComUtil/comutil.h
@@ -139,6 +139,7 @@ struct _dmmwalk {
 
 /* Package function prototypes */
 #if !defined(OSK)
+#include <sys/types.h>
 #include <ComUtil/comutil.arg>
 #endif
 
