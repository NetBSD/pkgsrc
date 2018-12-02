$NetBSD: patch-src_af_xap_xp_enchant__checker.cpp,v 1.1 2018/12/02 21:51:06 bsiegert Exp $

Adapt to new enchant API.

--- src/af/xap/xp/enchant_checker.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/xap/xp/enchant_checker.cpp
@@ -127,7 +127,7 @@ EnchantChecker::_suggestWord (const UT_U
 				pvSugg->addItem (ucszSugg);
 		}
 
-		enchant_dict_free_suggestions (m_dict, suggestions);
+		enchant_dict_free_string_list (m_dict, suggestions);
 	}
 
 	return pvSugg;
@@ -139,7 +139,7 @@ bool EnchantChecker::addToCustomDict (co
 
 	if (word && len) {
 		UT_UTF8String utf8 (word, len);
-		enchant_dict_add_to_personal (m_dict, utf8.utf8_str(), utf8.byteLength());
+		enchant_dict_add (m_dict, utf8.utf8_str(), utf8.byteLength());
 		return true;
 	}
 	return false;
@@ -150,7 +150,7 @@ bool EnchantChecker::isIgnored (const UT
 	UT_return_val_if_fail (m_dict, false);
 
 	UT_UTF8String ignore (toCorrect, toCorrectLen);
-	return enchant_dict_is_in_session (m_dict, ignore.utf8_str(), ignore.byteLength()) != 0;
+	return enchant_dict_is_added (m_dict, ignore.utf8_str(), ignore.byteLength()) != 0;
 }
 
 void EnchantChecker::ignoreWord (const UT_UCSChar *toCorrect, size_t toCorrectLen)
