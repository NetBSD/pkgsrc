$NetBSD: patch-ncurses_tinfo_parse__entry.c,v 1.1 2017/08/08 18:38:21 spz Exp $

from ftp://invisible-island.net/ncurses/6.0/ncurses-6.0-20170701.patch.gz
+ add/improve checks in tic's parser to address invalid input
 (Redhat #1464684, #1464685, #1464686, #1464691).
 + alloc_entry.c, add a check for a null-pointer.
 + parse_entry.c, add several checks for valid pointers as well as
   one check to ensure that a single character on a line is not 
   treated as the 2-character termcap short-name.

that's CVE-2017-10684 CVE-2017-10685 CVE-2017-11112 CVE-2017-11113

--- ncurses/tinfo/parse_entry.c.orig	2015-04-04 14:18:38.000000000 +0000
+++ ncurses/tinfo/parse_entry.c
@@ -236,13 +236,14 @@ _nc_parse_entry(struct entry *entryp, in
      * implemented it.  Note that the resulting terminal type was never the
      * 2-character name, but was instead the first alias after that.
      */
+#define ok_TC2(s) (isgraph(UChar(s)) && (s) != '|')
     ptr = _nc_curr_token.tk_name;
     if (_nc_syntax == SYN_TERMCAP
 #if NCURSES_XNAMES
 	&& !_nc_user_definable
 #endif
 	) {
-	if (ptr[2] == '|') {
+	if (ok_TC2(ptr[0]) && ok_TC2(ptr[1]) && (ptr[2] == '|')) {
 	    ptr += 3;
 	    _nc_curr_token.tk_name[2] = '\0';
 	}
@@ -284,9 +285,11 @@ _nc_parse_entry(struct entry *entryp, in
 	if (is_use || is_tc) {
 	    entryp->uses[entryp->nuses].name = _nc_save_str(_nc_curr_token.tk_valstring);
 	    entryp->uses[entryp->nuses].line = _nc_curr_line;
-	    entryp->nuses++;
-	    if (entryp->nuses > 1 && is_tc) {
-		BAD_TC_USAGE
+	    if (VALID_STRING(entryp->uses[entryp->nuses].name)) {
+		entryp->nuses++;
+		if (entryp->nuses > 1 && is_tc) {
+		    BAD_TC_USAGE
+		}
 	    }
 	} else {
 	    /* normal token lookup */
@@ -571,7 +574,7 @@ append_acs0(string_desc * dst, int code,
 static void
 append_acs(string_desc * dst, int code, char *src)
 {
-    if (src != 0 && strlen(src) == 1) {
+    if (VALID_STRING(src) && strlen(src) == 1) {
 	append_acs0(dst, code, *src);
     }
 }
@@ -832,15 +835,14 @@ postprocess_termcap(TERMTYPE *tp, bool h
 	    }
 
 	    if (tp->Strings[to_ptr->nte_index]) {
+		const char *s = tp->Strings[from_ptr->nte_index];
+		const char *t = tp->Strings[to_ptr->nte_index];
 		/* There's no point in warning about it if it's the same
 		 * string; that's just an inefficiency.
 		 */
-		if (strcmp(
-			      tp->Strings[from_ptr->nte_index],
-			      tp->Strings[to_ptr->nte_index]) != 0)
+		if (VALID_STRING(s) && VALID_STRING(t) && strcmp(s, t) != 0)
 		    _nc_warning("%s (%s) already has an explicit value %s, ignoring ko",
-				ap->to, ap->from,
-				_nc_visbuf(tp->Strings[to_ptr->nte_index]));
+				ap->to, ap->from, t);
 		continue;
 	    }
 
