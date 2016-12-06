$NetBSD: patch-i18nutil_source_utility_unicode.cxx,v 1.1 2016/12/06 15:21:00 ryoon Exp $

--- i18nutil/source/utility/unicode.cxx.orig	2016-10-28 14:50:26.000000000 +0000
+++ i18nutil/source/utility/unicode.cxx
@@ -957,6 +957,32 @@ OString SAL_CALL unicode::getExemplarLan
             sRet = "sa-Sidd";
             break;
 #endif
+#if (U_ICU_VERSION_MAJOR_NUM >= 58)
+        case USCRIPT_ADLAM:
+            sRet = "mis";   // Adlm - Adlam for Fulani, no language code
+            break;
+        case USCRIPT_BHAIKSUKI:
+            sRet = "mis";   // Bhks - Bhaiksuki for some Buddhist texts, no language code
+            break;
+        case USCRIPT_MARCHEN:
+            sRet = "bo-Marc";
+            break;
+        case USCRIPT_NEWA:
+            sRet = "new-Newa";
+            break;
+        case USCRIPT_OSAGE:
+            sRet = "osa-Osge";
+            break;
+        case USCRIPT_HAN_WITH_BOPOMOFO:
+            sRet = "mis";   // Hanb - Han with Bopomofo, zh-Hanb ?
+            break;
+        case USCRIPT_JAMO:
+            sRet = "mis";   // Jamo - Jamo subset of Hangul, ko-Jamo ?
+            break;
+        case USCRIPT_SYMBOLS_EMOJI:
+            sRet = "mis";   // Zsye - Emoji variant
+            break;
+#endif
     }
     return sRet;
 }
