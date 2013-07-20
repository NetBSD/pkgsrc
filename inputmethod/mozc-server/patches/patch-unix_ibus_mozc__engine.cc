$NetBSD: patch-unix_ibus_mozc__engine.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

* I am not sure.

--- unix/ibus/mozc_engine.cc.orig	2013-07-17 02:37:50.000000000 +0000
+++ unix/ibus/mozc_engine.cc
@@ -265,7 +265,7 @@ bool GetSurroundingText(IBusEngine *engi
   }
 
   const uint32 selection_start = min(cursor_pos, anchor_pos);
-  const uint32 selection_length = abs(info->relative_selected_length);
+  const uint32 selection_length = ::abs(info->relative_selected_length);
   info->preceding_text = surrounding_text.substr(0, selection_start);
   Util::SubString(surrounding_text,
                   selection_start,
