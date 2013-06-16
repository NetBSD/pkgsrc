$NetBSD: patch-lily_volta-repeat-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/volta-repeat-iterator.cc.orig	2013-06-16 19:24:27.000000000 +0000
+++ lily/volta-repeat-iterator.cc
@@ -94,7 +94,7 @@ Volta_repeat_iterator::next_element (boo
     {
       if (alt_count_)
         {
-          string repstr = to_string (rep_count_ - alt_count_ + done_count_) + ".";
+          string repstr = ::to_string (rep_count_ - alt_count_ + done_count_) + ".";
           if (done_count_ > 1)
             {
               add_repeat_command (scm_list_n (ly_symbol2scm ("volta"), SCM_BOOL_F, SCM_UNDEFINED));
@@ -104,7 +104,7 @@ Volta_repeat_iterator::next_element (boo
             }
 
           if (done_count_ == 1 && alt_count_ < rep_count_)
-            repstr = "1.--" + to_string (rep_count_ - alt_count_ + done_count_) + ".";
+            repstr = "1.--" + ::to_string (rep_count_ - alt_count_ + done_count_) + ".";
 
           if (done_count_ <= alt_count_)
             add_repeat_command (scm_list_n (ly_symbol2scm ("volta"),
