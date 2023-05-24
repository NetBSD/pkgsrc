$NetBSD: patch-src_ptimec.hh,v 1.1 2023/05/24 22:42:53 he Exp $

Don't print time_t as if it's a long; it doesn't have to be
and may be a long long (as on NetBSD).

--- src/ptimec.hh.orig	2022-08-30 20:33:38.000000000 +0000
+++ src/ptimec.hh
@@ -333,7 +333,7 @@ ftime_s(char* dst, off_t& off_inout, ssi
 {
     time_t t = tm2sec(&tm.et_tm);
 
-    snprintf(&dst[off_inout], len - off_inout, "%ld", t);
+    snprintf(&dst[off_inout], len - off_inout, "%lld", (long long)t);
     off_inout = strlen(dst);
 }
 
@@ -391,7 +391,7 @@ ftime_q(char* dst, off_t& off_inout, ssi
 {
     time_t t = tm2sec(&tm.et_tm);
 
-    snprintf(&dst[off_inout], len - off_inout, "%lx", t);
+    snprintf(&dst[off_inout], len - off_inout, "%llx", (long long)t);
     off_inout = strlen(dst);
 }
 
