$NetBSD: patch-modules_scim_novel__pinyin__imengine.cpp,v 1.1 2013/03/20 05:25:58 obache Exp $

* fixes bogus NULL usage, as Integer 0.

--- modules/scim/novel_pinyin_imengine.cpp.orig	2008-10-05 07:55:31.000000000 +0000
+++ modules/scim/novel_pinyin_imengine.cpp
@@ -1690,7 +1690,7 @@ PinyinInstance::calc_lookup_table (){
 	    }
 	}
     }else
-	last_token = NULL;
+	last_token = 0;
 
     PhraseItemWithFreq item;
     
@@ -1782,7 +1782,7 @@ PinyinInstance::calc_lookup_table (){
 	    }
 	}
 	g_array_sort(m_phrase_items_with_freq, lookup_table_sort);
-	phrase_token_t last_token = NULL;
+	phrase_token_t last_token = 0;
 	for ( size_t m = 0; m < m_phrase_items_with_freq->len; ++m){
 	    PhraseItemWithFreq * item = &g_array_index(m_phrase_items_with_freq, PhraseItemWithFreq, m);
 	    if ( last_token != item->m_token )
