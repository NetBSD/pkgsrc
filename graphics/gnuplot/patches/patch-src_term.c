$NetBSD: patch-src_term.c,v 1.1 2020/09/22 19:08:55 bsiegert Exp $

Fix for CVE-2020-25559 and CVE-2020-25412, from upstream

--- src/term.c.orig	2019-11-19 21:57:18.000000000 +0000
+++ src/term.c
@@ -191,6 +191,7 @@ char *enhanced_cur_text = NULL;
 double enhanced_fontscale = 1.0;
 char enhanced_escape_format[16] = "";
 double enhanced_max_height = 0.0, enhanced_min_height = 0.0;
+#define ENHANCED_TEXT_MAX (&enhanced_text[MAX_LINE_LEN])
 /* flag variable to disable enhanced output of filenames, mainly. */
 TBOOLEAN ignore_enhanced_text = FALSE;
 
@@ -2207,6 +2208,9 @@ fflush_binary()
 void
 do_enh_writec(int c)
 {
+    /* Guard against buffer overflow */
+    if (enhanced_cur_text >= ENHANCED_TEXT_MAX)
+	return;
     /* note: c is meant to hold a char, but is actually an int, for
      * the same reasons applying to putc() and friends */
     *enhanced_cur_text++ = c;
@@ -2361,7 +2365,7 @@ enhanced_recursion(
 			    ++p;
 			if (*p != *start_of_fontname) {
 			    int_warn(NO_CARET, "cannot interpret font name %s", start_of_fontname);
-			    p = start_of_fontname;
+			    break;
 			}
 			start_of_fontname++;
 			end_of_fontname = p++;
