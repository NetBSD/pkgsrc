$NetBSD: patch-i18nutil_source_utility_unicode.cxx,v 1.7 2023/01/22 17:56:04 ryoon Exp $

--- i18nutil/source/utility/unicode.cxx.orig	2022-12-28 10:19:16.000000000 +0000
+++ i18nutil/source/utility/unicode.cxx
@@ -25,6 +25,7 @@
 #include <sal/log.hxx>
 #include <unicode/uchar.h>
 #include <unicode/numfmt.h>
+#include <unicode/regex.h>
 #include "unicode_data.h"
 #include <rtl/character.hxx>
 #include <o3tl/string_view.hxx>
