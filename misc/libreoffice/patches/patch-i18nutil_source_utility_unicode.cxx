$NetBSD: patch-i18nutil_source_utility_unicode.cxx,v 1.8 2023/02/13 14:59:36 ryoon Exp $

--- i18nutil/source/utility/unicode.cxx.orig	2023-01-25 14:26:33.000000000 +0000
+++ i18nutil/source/utility/unicode.cxx
@@ -24,6 +24,7 @@
 #include <i18nutil/unicode.hxx>
 #include <sal/log.hxx>
 #include <unicode/numfmt.h>
+#include <unicode/regex.h>
 #include <unicode/uchar.h>
 #include "unicode_data.h"
 #include <rtl/character.hxx>
