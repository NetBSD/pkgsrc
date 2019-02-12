$NetBSD: patch-src_output.h,v 1.3 2019/02/12 16:49:31 maya Exp $

constify, for clang

--- src/output.h.orig	2018-12-28 13:01:03.000000000 +0000
+++ src/output.h
@@ -30,7 +30,7 @@ enum {
 
 void set_color(rgb_color_t c, rgb_color_t c2);
 
-void writembs_check(char *mbs, const char *mbs_name, bool critical, const char *file, long line);
+void writembs_check(const char *mbs, const char *mbs_name, bool critical, const char *file, long line);
 #define writembs(mbs) writembs_check((mbs), #mbs, true, __FILE__, __LINE__)
 #define writembs_nofail(mbs) writembs_check((mbs), #mbs, false, __FILE__, __LINE__)
 
