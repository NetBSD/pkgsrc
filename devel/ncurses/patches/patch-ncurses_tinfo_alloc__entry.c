$NetBSD: patch-ncurses_tinfo_alloc__entry.c,v 1.3 2020/01/11 01:39:19 kim Exp $

Fix for CVE-2018-19211 cherry-picked from upstream patchlevel 20180414.

+ add a null-pointer check in _nc_parse_entry to handle an error when
  a use-name is invalid syntax (report by Chung-Yi Lin).
+ also add/improve null-pointer checks in other places

--- ncurses/tinfo/alloc_entry.c
+++ ncurses/tinfo/alloc_entry.c
@@ -229,6 +229,9 @@ _nc_merge_entry(ENTRY * const target, ENTRY * const source)
     TERMTYPE2 *from = &(source->tterm);
     unsigned i;
 
+    if (source == 0 || from == 0 || target == 0 || to == 0)
+	return;
+
 #if NCURSES_XNAMES
     _nc_align_termtype(to, from);
 #endif
