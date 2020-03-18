$NetBSD: patch-src_Misc_Language.cpp,v 1.1 2020/03/18 17:53:18 joerg Exp $

Workaround excessive stack use in clang during codegen.

--- src/Misc/Language.cpp.orig	2020-03-18 13:57:20.504966123 +0000
+++ src/Misc/Language.cpp
@@ -127,7 +127,8 @@ void Language::SetLanguageMap()
          "ca-ES" << tr("Catalan") + QString(" - ") + tr("Spain") <<
          "km"    << tr("Central Khmer") <<
          "ch"    << tr("Chamorro") <<
-         "ce"    << tr("Chechen") <<
+         "ce"    << tr("Chechen");
+    data <<
          "zh"    << tr("Chinese") <<
          "zh-CN" << tr("Chinese") + QString(" - ") + tr("China") <<
          "zh-HK" << tr("Chinese") + QString(" - ") + tr("Hong Kong") <<
@@ -178,7 +179,8 @@ void Language::SetLanguageMap()
          "gd-IE" << tr("Gaelic") + QString(" - ") + tr("Ireland") <<
          "gl"    << tr("Galician") <<
          "lg"    << tr("Ganda") <<
-         "ka"    << tr("Georgian") <<
+         "ka"    << tr("Georgian");
+    data <<
          "de"    << tr("German") <<
          "de-AT" << tr("German") + QString(" - ") + tr("Austria") <<
          "de-DE" << tr("German") + QString(" - ") + tr("Germany") <<
@@ -226,7 +228,8 @@ void Language::SetLanguageMap()
          "kj"    << tr("Kuanyama") <<
          "ku"    << tr("Kurdish") <<
          "lo"    << tr("Lao") <<
-         "la"    << tr("Latin") <<
+         "la"    << tr("Latin");
+    data <<
          "lv"    << tr("Latvian") <<
          "lv-LV" << tr("Latvian") + QString(" - ") + tr("Latvia") <<
          "li"    << tr("Limburgan") <<
@@ -275,7 +278,8 @@ void Language::SetLanguageMap()
          "ro-MO" << tr("Romanian") + QString(" - ") + tr("Moldova") <<
          "ro-RO" << tr("Romanian") + QString(" - ") + tr("Romania") <<
          "rm"    << tr("Romansh") <<
-         "rn"    << tr("Rundi") <<
+         "rn"    << tr("Rundi");
+    data <<
          "ru"    << tr("Russian") <<
          "ru-MO" << tr("Russian") + QString(" - ") + tr("Moldova") <<
          "sm"    << tr("Samoan") <<
@@ -326,7 +330,8 @@ void Language::SetLanguageMap()
          "te"    << tr("Telugu") <<
          "th"    << tr("Thai") <<
          "bo"    << tr("Tibetan") <<
-         "ti"    << tr("Tigrinya") <<
+         "ti"    << tr("Tigrinya");
+    data <<
          "to"    << tr("Tonga") <<
          "ts"    << tr("Tsonga") <<
          "tn"    << tr("Tswana") <<
@@ -376,7 +381,8 @@ void Language::SetLanguageMap()
          "awa"   << tr("Awadhi") <<
          "ban"   << tr("Balinese") <<
          "bat"   << tr("Baltic languages") <<
-         "bal"   << tr("Baluchi") <<
+         "bal"   << tr("Baluchi");
+    data <<
          "bai"   << tr("Bamileke languages") <<
          "bad"   << tr("Banda languages") <<
          "bnt"   << tr("Bantu languages") <<
@@ -425,7 +431,8 @@ void Language::SetLanguageMap()
          "doi"   << tr("Dogri") <<
          "dgr"   << tr("Dogrib") <<
          "dra"   << tr("Dravidian languages") <<
-         "dua"   << tr("Duala") <<
+         "dua"   << tr("Duala");
+    data <<
          "dum"   << tr("Dutch- Middle (ca.1050-1350)") <<
          "dyu"   << tr("Dyula") <<
          "frs"   << tr("Eastern Frisian") <<
@@ -474,7 +481,8 @@ void Language::SetLanguageMap()
          "inc"   << tr("Indic languages") <<
          "ine"   << tr("Indo-European languages") <<
          "inh"   << tr("Ingush") <<
-         "ira"   << tr("Iranian languages") <<
+         "ira"   << tr("Iranian languages");
+    data <<
          "mga"   << tr("Irish- Middle (900-1200)") <<
          "sga"   << tr("Irish- Old (to 900)") <<
          "iro"   << tr("Iroquoian languages") <<
@@ -524,7 +532,8 @@ void Language::SetLanguageMap()
          "mai"   << tr("Maithili") <<
          "mak"   << tr("Makasar") <<
          "mnc"   << tr("Manchu") <<
-         "mdr"   << tr("Mandar") <<
+         "mdr"   << tr("Mandar");
+    data <<
          "man"   << tr("Mandingo") <<
          "mni"   << tr("Manipuri") <<
          "mno"   << tr("Manobo languages") <<
@@ -573,7 +582,8 @@ void Language::SetLanguageMap()
          "pap"   << tr("Papiamento") <<
          "paa"   << tr("Papuan languages") <<
          "gug"   << tr("Paraguayan Guaraní") <<
-         "peo"   << tr("Persian- Old (ca.600-400 B.C.)") <<
+         "peo"   << tr("Persian- Old (ca.600-400 B.C.)");
+    data <<
          "phi"   << tr("Philippine languages") <<
          "phn"   << tr("Phoenician") <<
          "pon"   << tr("Pohnpeian") <<
@@ -623,7 +633,8 @@ void Language::SetLanguageMap()
          "tet"   << tr("Tetum") <<
          "tig"   << tr("Tigre") <<
          "tem"   << tr("Timne") <<
-         "tiv"   << tr("Tiv") <<
+         "tiv"   << tr("Tiv");
+    data <<
          "tli"   << tr("Tlingit") <<
          "tpi"   << tr("Tok Pisin") <<
          "tkl"   << tr("Tokelau") <<
