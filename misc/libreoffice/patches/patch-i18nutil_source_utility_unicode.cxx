$NetBSD: patch-i18nutil_source_utility_unicode.cxx,v 1.6 2022/08/22 13:58:32 ryoon Exp $

--- i18nutil/source/utility/unicode.cxx.orig	2022-08-10 14:14:32.000000000 +0000
+++ i18nutil/source/utility/unicode.cxx
@@ -24,6 +24,7 @@
 #include <i18nutil/unicode.hxx>
 #include <sal/log.hxx>
 #include <unicode/numfmt.h>
+#include <unicode/regex.h>
 #include "unicode_data.h"
 #include <rtl/character.hxx>
 #include <o3tl/string_view.hxx>
