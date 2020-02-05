$NetBSD: patch-i18nutil_source_utility_unicode.cxx,v 1.5 2020/02/05 14:10:35 ryoon Exp $

--- i18nutil/source/utility/unicode.cxx.orig	2019-01-23 19:35:25.000000000 +0000
+++ i18nutil/source/utility/unicode.cxx
@@ -25,6 +25,7 @@
 #include <i18nutil/unicode.hxx>
 #include <sal/log.hxx>
 #include <unicode/numfmt.h>
+#include <unicode/regex.h>
 #include "unicode_data.h"
 #include <rtl/character.hxx>
 #include <memory>
