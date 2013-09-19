$NetBSD: patch-src_lookup_pinyin__lookup.cpp,v 1.2 2013/09/19 13:01:01 obache Exp $

* use C++ style include files.
* resolve "call of overloaded `log(int)' is ambiguous"
* fixes bogus NULL usage, as Integer 0.

--- src/lookup/pinyin_lookup.cpp.orig	2009-03-08 03:43:51.000000000 +0000
+++ src/lookup/pinyin_lookup.cpp
@@ -20,8 +20,8 @@
  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
  */
 
-#include <math.h>
-#include <assert.h>
+#include <cmath>
+#include <cassert>
 #include <iostream>
 #include "stl_lite.h"
 #include "novel_types.h"
@@ -158,7 +158,7 @@ bool PinyinLookup::get_best_match(Pinyin
     }
     
     lookup_key_t initial_key = sentence_start;
-    lookup_value_t initial_value(log(1));
+    lookup_value_t initial_value(log((gfloat)1));
     initial_value.m_handles[1] = sentence_start;
     GArray * initial_step_content = (GArray *) g_ptr_array_index(m_steps_content, 0);
     initial_step_content = g_array_append_val(initial_step_content, initial_value);
@@ -379,7 +379,7 @@ bool PinyinLookup::final_step(MatchResul
     g_array_set_size(results, m_steps_content->len);
     for ( size_t i = 0 ; i < m_steps_content->len ; ++i){
 	phrase_token_t * token = &g_array_index(results, phrase_token_t, i);
-	*token = NULL;
+	*token = 0;
     }
     //find max element
     size_t last_step_pos = m_steps_content->len - 1;
@@ -430,7 +430,7 @@ bool PinyinLookup::train_result(PinyinKe
     guint32 train_factor = 23;
     for ( size_t i = 0; i < constraints->len; ++i){
 	phrase_token_t * token = &g_array_index(results, phrase_token_t, i);
-	if ( *token == NULL )
+	if ( *token == 0 )
 	    continue;
 	lookup_constraint_t * constraint = &g_array_index(constraints, lookup_constraint_t, i);
 	if (train_next || CONSTRAINT_ONESTEP == constraint->m_type ){
@@ -484,7 +484,7 @@ bool PinyinLookup::convert_to_utf8(Match
     result_string = g_strdup("");
     for ( size_t i = 0; i < results->len; ++i){
 	phrase_token_t * token = &g_array_index(results, phrase_token_t, i);
-	if ( NULL == *token )
+	if ( 0 == *token )
 	    continue;
 	m_phrase_index->get_phrase_item(*token, m_cache_phrase_item);
 	utf16_t buffer[MAX_PHRASE_LENGTH];
