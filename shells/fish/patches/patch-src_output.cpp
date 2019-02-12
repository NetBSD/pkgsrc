$NetBSD: patch-src_output.cpp,v 1.3 2019/02/12 16:49:31 maya Exp $

Work around NetBSD curses.

--- src/output.cpp.orig	2018-12-28 13:01:03.000000000 +0000
+++ src/output.cpp
@@ -63,10 +63,14 @@ unsigned char index_for_color(rgb_color_
     return c.to_term256_index();
 }
 
-static bool write_color_escape(char *todo, unsigned char idx, bool is_fg) {
+static bool write_color_escape(const char *todo, unsigned char idx, bool is_fg) {
     if (term_supports_color_natively(idx)) {
         // Use tparm to emit color escape.
+#ifdef __NetBSD__
         writembs(tparm(todo, idx));
+#else
+        writembs(tparm((char *)todo, idx));
+#endif
         return true;
     }
 
@@ -550,7 +554,7 @@ rgb_color_t parse_color(const env_var_t 
 }
 
 /// Write specified multibyte string.
-void writembs_check(char *mbs, const char *mbs_name, bool critical, const char *file, long line) {
+void writembs_check(const char *mbs, const char *mbs_name, bool critical, const char *file, long line) {
     if (mbs != NULL) {
         tputs(mbs, 1, &writeb);
     } else if (critical) {
