$NetBSD: patch-unix_ibus_mozc__engine.cc,v 1.1 2013/04/29 09:52:18 ryoon Exp $

* I am not sure.

--- unix/ibus/mozc_engine.cc.orig	2012-08-31 05:36:43.000000000 +0000
+++ unix/ibus/mozc_engine.cc
@@ -756,7 +756,7 @@ bool MozcEngine::ExecuteCallback(IBusEng
       //     on size_t, not uint32.
       string selection_text;
       const uint32 selection_start = min(cursor_pos, anchor_pos);
-      const uint32 selection_length = abs(relative_selected_length);
+      const uint32 selection_length = ::abs(relative_selected_length);
       Util::SubString(surrounding_text,
                       selection_start,
                       selection_length,
