$NetBSD: patch-src_common_locale.cpp,v 1.1 2018/12/03 12:15:03 jperkin Exp $

Remove broken SunOS section that is no longer needed.
https://gitlab.com/mbunkus/mkvtoolnix/issues/2450

--- src/common/locale.cpp.orig	2018-12-01 11:15:36.000000000 +0000
+++ src/common/locale.cpp
@@ -292,12 +292,6 @@ get_local_charset() {
   setlocale(LC_CTYPE, "");
 #if defined(COMP_MINGW) || defined(COMP_MSC)
   lc_charset = "CP" + to_string(GetACP());
-#elif defined(SYS_SOLARIS)
-  int i;
-
-  lc_charset = nl_langinfo(CODESET);
-  if (parse_number(lc_charset, i))
-    lc_charset = "ISO"s + lc_charset + "-US"s;
 #elif HAVE_NL_LANGINFO
   lc_charset = nl_langinfo(CODESET);
 #elif HAVE_LOCALE_CHARSET
