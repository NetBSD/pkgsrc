$NetBSD: patch-src_xmltv.c,v 1.1 2013/05/11 21:38:22 joerg Exp $

--- src/xmltv.c.orig	2013-05-10 14:43:03.000000000 +0000
+++ src/xmltv.c
@@ -118,9 +118,9 @@ const int num_timezones = sizeof( date_m
 typedef struct {
     const char *code;
     const char *name;
-} locale_t;
+} my_locale_t;
 
-static locale_t locale_table[] = {
+static my_locale_t locale_table[] = {
     {"AA", "Afar"},           {"AB", "Abkhazian"},      {"AF", "Afrikaans"},
     {"AM", "Amharic"},        {"AR", "Arabic"},         {"AS", "Assamese"},
     {"AY", "Aymara"},         {"AZ", "Azerbaijani"},    {"BA", "Bashkir"},
@@ -168,7 +168,7 @@ static locale_t locale_table[] = {
     {"XH", "Xhosa"},          {"YO", "Yoruba"},         {"ZH", "Chinese"},
     {"ZU", "Zulu"} };
 
-const int num_locales = sizeof( locale_table ) / sizeof( locale_t );
+const int num_locales = sizeof( locale_table ) / sizeof( *locale_table );
 
 /**
  * Timezone parsing code based loosely on the algorithm in
