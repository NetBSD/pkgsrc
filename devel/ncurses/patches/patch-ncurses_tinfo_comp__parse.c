$NetBSD: patch-ncurses_tinfo_comp__parse.c,v 1.1 2020/01/11 01:39:19 kim Exp $

Fix for CVE-2018-19211 cherry-picked from upstream patchlevel 20180414.

+ add a null-pointer check in _nc_parse_entry to handle an error when
  a use-name is invalid syntax (report by Chung-Yi Lin).
+ also add/improve null-pointer checks in other places

--- ncurses/tinfo/comp_parse.c
+++ ncurses/tinfo/comp_parse.c
@@ -317,6 +437,9 @@ _nc_resolve_uses2(bool fullresolve, bool literal)
 	    char *lookfor = qp->uses[i].name;
 	    long lookline = qp->uses[i].line;
 
+	    if (lookfor == 0)
+		continue;
+
 	    foundit = FALSE;
 
 	    _nc_set_type(child);
@@ -394,7 +517,8 @@ _nc_resolve_uses2(bool fullresolve, bool literal)
 		     * subsequent pass.
 		     */
 		    for (i = 0; i < qp->nuses; i++)
-			if (qp->uses[i].link->nuses) {
+			if (qp->uses[i].link
+			    && qp->uses[i].link->nuses) {
 			    DEBUG(2, ("%s: use entry %d unresolved",
 				      _nc_first_name(qp->tterm.term_names), i));
 			    goto incomplete;
