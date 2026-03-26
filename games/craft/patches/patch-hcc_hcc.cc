$NetBSD: patch-hcc_hcc.cc,v 1.1 2026/03/26 02:53:51 dholland Exp $

Avoid undefined behavior. These functions don't return values.

--- hcc/hcc.cc~	2026-03-26 02:19:08.304087599 +0000
+++ hcc/hcc.cc
@@ -192,7 +192,7 @@ void pass_1_error (int line_no, const ch
    exit   (1);
   }
 
-bool pass_1 (char src_name [])
+void pass_1 (char src_name [])
   {bool inside_comment;
    bool inside_prc;
    int  symbol_no;
@@ -1122,7 +1122,7 @@ void sub_ref (int ref_n)
  
   }
 
-bool pass_2 (char obj_name [])
+void pass_2 (char obj_name [])
   {int  line_no;
    int  char_no;
    bool within_string;
