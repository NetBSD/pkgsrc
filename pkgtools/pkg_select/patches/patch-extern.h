$NetBSD: patch-extern.h,v 1.1 2013/11/29 23:13:56 dholland Exp $

Fix const correctness.

--- extern.h~	2009-03-08 14:25:53.000000000 +0000
+++ extern.h
@@ -50,7 +50,7 @@ extern int entry_search(Etree **, int);
 /* list mgt */
 extern int find_value(Etree **, char *);
 extern char **pkgfind(const char *, const char *, int);
-extern Etree **build_tree_from_list(const char **);
+extern Etree **build_tree_from_list(const char *const *);
 
 extern int info_win(WINDOW *, char *, char *);
 extern int more_file(WINDOW *, char *, int, int, int, int);
