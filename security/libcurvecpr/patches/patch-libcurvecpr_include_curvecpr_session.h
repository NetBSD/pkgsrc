$NetBSD: patch-libcurvecpr_include_curvecpr_session.h,v 1.1 2019/12/22 22:28:54 joerg Exp $

--- libcurvecpr/include/curvecpr/session.h.orig	2019-12-22 17:53:48.570243631 +0000
+++ libcurvecpr/include/curvecpr/session.h
@@ -1,7 +1,7 @@
 #ifndef __CURVECPR_SESSION_H
 #define __CURVECPR_SESSION_H
 
-#include <sodium/crypto_uint64.h>
+#include <curvecpr/bytes.h>
 
 struct curvecpr_session {
     /* Any extensions. */
