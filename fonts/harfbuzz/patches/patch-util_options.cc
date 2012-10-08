$NetBSD: patch-util_options.cc,v 1.1 2012/10/08 19:20:33 adam Exp $

Avoid non-portable _setmode().

--- util/options.cc.orig	2012-10-08 18:14:30.000000000 +0000
+++ util/options.cc
@@ -525,9 +525,6 @@ font_options_t::get_font (void) const
       /* read it */
       GString *gs = g_string_new (NULL);
       char buf[BUFSIZ];
-#ifdef HAVE__SETMODE
-      _setmode (fileno (stdin), _O_BINARY);
-#endif
       while (!feof (stdin)) {
 	size_t ret = fread (buf, 1, sizeof (buf), stdin);
 	if (ferror (stdin))
@@ -669,9 +666,6 @@ output_options_t::get_file_handle (void)
   if (output_file)
     fp = fopen (output_file, "wb");
   else {
-#ifdef HAVE__SETMODE
-    _setmode (fileno (stdout), _O_BINARY);
-#endif
     fp = stdout;
   }
   if (!fp)
