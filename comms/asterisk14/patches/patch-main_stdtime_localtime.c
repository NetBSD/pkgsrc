$NetBSD: patch-main_stdtime_localtime.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- main/stdtime/localtime.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/stdtime/localtime.c
@@ -67,6 +67,10 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <sys/stat.h>
 #include <fcntl.h>
 #endif
+#ifdef __sun
+#include <time.h>
+#include <xlocale.h>
+#endif
 
 #include "private.h"
 #include "tzfile.h"
@@ -733,7 +737,7 @@ static void *notify_daemon(void *data)
 			if (st.st_mtime > cur->mtime[0] || lst.st_mtime > cur->mtime[1]) {
 #ifdef TEST_FRAMEWORK
 				if (test) {
-					ast_test_status_update(test, "Removing cached TZ entry '%s' because underlying file changed. (%ld != %ld) or (%ld != %ld)\n", name, st.st_mtime, cur->mtime[0], lst.st_mtime, cur->mtime[1]);
+					ast_test_status_update(test, "Removing cached TZ entry '%s' because underlying file changed. (%jd != %jd) or (%jd != %jd)\n", name, (intmax_t)st.st_mtime, (intmax_t)cur->mtime[0], (intmax_t)lst.st_mtime, (intmax_t)cur->mtime[1]);
 				} else
 #endif
 				{
@@ -2417,6 +2421,23 @@ static struct locale_entry *find_by_name
 	return NULL;
 }
 
+#if HAVE_STRFTIME_L || HAVE_STRPTIME_L
+static locale_t ast_getlocale(const char *locale)
+{
+	struct locale_entry *cur;
+
+	AST_LIST_LOCK(&localelist);
+	if ((cur = find_by_name(locale)) == NULL) {
+		cur->locale = newlocale(LC_ALL_MASK, locale, NULL);
+		strcpy(cur->name, locale); /* SAFE */
+		AST_LIST_INSERT_TAIL(&localelist, cur, list);
+	}
+	AST_LIST_UNLOCK(&localelist);
+	return cur->locale;
+}
+#endif
+
+#if !HAVE_STRFTIME_L || !HAVE_STRPTIME_L
 static const char *store_by_locale(locale_t prevlocale)
 {
 	struct locale_entry *cur;
@@ -2474,6 +2495,7 @@ const char *ast_setlocale(const char *lo
 	AST_LIST_UNLOCK(&localelist);
 	return store_by_locale(prevlocale);
 }
+#endif
 #else
 const char *ast_setlocale(const char *unused)
 {
@@ -2487,7 +2509,9 @@ int ast_strftime_locale(char *buf, size_
 	char *format = ast_calloc(1, fmtlen), *fptr = format, *newfmt;
 	int decimals = -1, i, res;
 	long fraction;
+#if !HAVE_STRFTIME_L
 	const char *prevlocale;
+#endif
 
 	buf[0] = '\0';/* Ensure the buffer is initialized. */
 	if (!format) {
@@ -2542,6 +2566,14 @@ defcase:	*fptr++ = *tmp;
 	}
 	*fptr = '\0';
 #undef strftime
+#if HAVE_STRFTIME_L
+	if (locale) {
+		locale_t l = ast_getlocale(locale);
+		res = (int)strftime_l(buf, len, format, (struct tm *)tm, l);
+	} else {
+		res = (int)strftime(buf, len, format, (struct tm *)tm);
+	}
+#else
 	if (locale) {
 		prevlocale = ast_setlocale(locale);
 	}
@@ -2549,6 +2581,7 @@ defcase:	*fptr++ = *tmp;
 	if (locale) {
 		ast_setlocale(prevlocale);
 	}
+#endif
 	ast_free(format);
 	return res;
 }
@@ -2562,11 +2595,22 @@ char *ast_strptime_locale(const char *s,
 {
 	struct tm tm2 = { 0, };
 	char *res;
+#if !HAVE_STRPTIME_L
 	const char *prevlocale;
+#endif
 
+#if HAVE_STRPTIME_L
+	if (locale) {
+		locale_t l = ast_getlocale(locale);
+		res = strptime_l(s, format, &tm2, l);
+	} else {
+		res = strptime(s, format, &tm2);
+	}
+#else
 	prevlocale = ast_setlocale(locale);
 	res = strptime(s, format, &tm2);
 	ast_setlocale(prevlocale);
+#endif
 	/* ast_time and tm are not the same size - tm is a subset of
 	 * ast_time.  Hence, the size of tm needs to be used for the
 	 * memcpy
