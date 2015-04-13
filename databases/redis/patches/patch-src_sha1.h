$NetBSD: patch-src_sha1.h,v 1.1 2015/04/13 11:33:35 fhajny Exp $

Fix for u_int32_t missing on SunOS.

--- src/sha1.h.orig	2015-04-01 14:01:44.000000000 +0000
+++ src/sha1.h
@@ -5,6 +5,8 @@ By Steve Reid <steve@edmweb.com>
 100% Public Domain
 */
 
+#include "solarisfixes.h"
+
 typedef struct {
     u_int32_t state[5];
     u_int32_t count[2];
