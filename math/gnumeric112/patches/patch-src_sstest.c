$NetBSD: patch-src_sstest.c,v 1.1 2026/03/10 06:34:16 wiz Exp $

sstest: replace `bool` type with `gboolean`
https://gitlab.gnome.org/GNOME/gnumeric/-/commit/0de4c0a45f078ec211fd372da4103b09cb718b1b

--- src/sstest.c.orig	2026-02-11 02:07:03.000000000 +0000
+++ src/sstest.c
@@ -898,7 +898,7 @@ static gboolean
 /* ------------------------------------------------------------------------- */
 
 static gboolean
-check_help_expression (const char *text, GnmFunc const *fd, bool localized)
+check_help_expression (const char *text, GnmFunc const *fd, gboolean localized)
 {
 	GnmConventions const *convs = gnm_conventions_default;
 	GnmParsePos pp;
