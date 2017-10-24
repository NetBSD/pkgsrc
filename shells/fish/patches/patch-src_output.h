$NetBSD: patch-src_output.h,v 1.1 2017/10/24 03:51:41 maya Exp $

--- src/output.h.orig	2017-06-03 12:45:13.000000000 +0000
+++ src/output.h
@@ -29,7 +29,7 @@ enum {
 
 void set_color(rgb_color_t c, rgb_color_t c2);
 
-void writembs_check(char *mbs, const char *mbs_name, const char *file, long line);
+void writembs_check(const char *mbs, const char *mbs_name, const char *file, long line);
 #define writembs(mbs) writembs_check((mbs), #mbs, __FILE__, __LINE__)
 
 int writech(wint_t ch);
