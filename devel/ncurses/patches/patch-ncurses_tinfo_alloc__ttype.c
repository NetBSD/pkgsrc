$NetBSD: patch-ncurses_tinfo_alloc__ttype.c,v 1.1 2020/01/11 01:39:19 kim Exp $

Fix for CVE-2018-19211 cherry-picked from upstream patchlevel 20180414.

+ add a null-pointer check in _nc_parse_entry to handle an error when
  a use-name is invalid syntax (report by Chung-Yi Lin).
+ also add/improve null-pointer checks in other places

--- ncurses/tinfo/alloc_ttype.c
+++ ncurses/tinfo/alloc_ttype.c
@@ -388,12 +388,16 @@ adjust_cancels(TERMTYPE2 *to, TERMTYPE2 *from)
 NCURSES_EXPORT(void)
 _nc_align_termtype(TERMTYPE2 *to, TERMTYPE2 *from)
 {
-    int na = (int) NUM_EXT_NAMES(to);
-    int nb = (int) NUM_EXT_NAMES(from);
+    int na;
+    int nb;
     char **ext_Names;
 
-    DEBUG(2, ("align_termtype to(%d:%s), from(%d:%s)", na, to->term_names,
-	      nb, from->term_names));
+    na = to ? ((int) NUM_EXT_NAMES(to)) : 0;
+    nb = from ? ((int) NUM_EXT_NAMES(from)) : 0;
+
+    DEBUG(2, ("align_termtype to(%d:%s), from(%d:%s)",
+	      na, to ? NonNull(to->term_names) : "?",
+	      nb, from ? NonNull(from->term_names) : "?"));
 
     if (na != 0 || nb != 0) {
 	int ext_Booleans, ext_Numbers, ext_Strings;
