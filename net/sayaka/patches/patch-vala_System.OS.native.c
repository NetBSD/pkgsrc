$NetBSD: patch-vala_System.OS.native.c,v 1.1 2020/02/07 12:39:08 tsutsui Exp $

- pull post 3.4.2 upstream fix
  "Fix native_term_support_sixel to parse "\x1b[?63;4c" correctly."
  https://github.com/isaki68k/sayaka/commit/5e5ea0f8911f3b52fbe9231e8f547316675919ec

--- vala/System.OS.native.c.orig	2020-02-01 06:29:17.000000000 +0000
+++ vala/System.OS.native.c
@@ -102,7 +102,14 @@ native_term_support_sixel()
 		e = strchr(p, ';');
 		if (e) {
 			*e++ = '\0';
+		} else {
+			e = strrchr(p, 'c');
+			if (e) {
+				*e = '\0';
+				e = NULL;
+			}
 		}
+
 		if (strcmp(p, "4") == 0) {
 			return 1;
 		}
