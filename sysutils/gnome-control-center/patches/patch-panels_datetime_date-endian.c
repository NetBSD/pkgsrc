$NetBSD: patch-panels_datetime_date-endian.c,v 1.1 2020/11/10 18:22:23 nia Exp $

NetBSD does not have uselocale.

--- panels/datetime/date-endian.c.orig	2020-10-03 22:47:30.400756400 +0000
+++ panels/datetime/date-endian.c
@@ -154,18 +154,22 @@ date_endian_get_for_lang (const char *la
 	locale_t old_locale;
 	DateEndianess endian;
 
+#ifndef __NetBSD__
 	locale = newlocale (LC_TIME_MASK, lang, (locale_t) 0);
 	if (locale == (locale_t) 0)
 		g_warning ("Failed to create locale %s: %s", lang, g_strerror (errno));
 	else
 		old_locale = uselocale (locale);
+#endif
 
 	endian = date_endian_get_default (verbose);
 
+#ifndef __NetBSD__
 	if (locale != (locale_t) 0) {
 		uselocale (old_locale);
 		freelocale (locale);
 	}
+#endif
 
 	return endian;
 }
