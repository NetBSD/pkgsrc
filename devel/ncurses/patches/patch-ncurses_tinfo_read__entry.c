$NetBSD: patch-ncurses_tinfo_read__entry.c,v 1.1 2020/01/11 01:39:19 kim Exp $

Fix for CVE-2018-19211 cherry-picked from upstream patchlevel 20180414.

+ add a null-pointer check in _nc_parse_entry to handle an error when
  a use-name is invalid syntax (report by Chung-Yi Lin).
+ also add/improve null-pointer checks in other places

--- ncurses/tinfo/read_entry.c
+++ ncurses/tinfo/read_entry.c
@@ -837,6 +837,9 @@ _nc_read_entry2(const char *const name, char *const filename, TERMTYPE2 *const t
 {
     int code = TGETENT_NO;
 
+    if (name == 0)
+	return _nc_read_entry2("", filename, tp);
+
     _nc_SPRINTF(filename, _nc_SLIMIT(PATH_MAX)
 		"%.*s", PATH_MAX - 1, name);
 
