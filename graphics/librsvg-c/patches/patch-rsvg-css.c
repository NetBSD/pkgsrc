$NetBSD: patch-rsvg-css.c,v 1.1 2025/11/16 10:38:27 leot Exp $

Fix build with gcc14.

Otherwise it would fail with:

 rsvg-css.c:866:20: error: assignment to 'xmlStructuredErrorFunc' {aka 'void (*)(void *, const struct _xmlError *)'} from incompatible pointer type 'void (*)(void *, xmlError *)' {aka 'void (*)(void *, struct _xmlError *)'} [-Wincompatible-pointer-types]

--- rsvg-css.c.orig	2025-11-16 10:30:33.515578178 +0000
+++ rsvg-css.c
@@ -839,7 +839,7 @@ rsvg_css_parse_overflow (const char *str
 }
 
 static void
-rsvg_xml_noerror (void *data, xmlErrorPtr error)
+rsvg_xml_noerror (void *data, const xmlError *error)
 {
 }
 
