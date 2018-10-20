$NetBSD: patch-ncurses_tinfo_parse__entry.c,v 1.3.2.2 2018/10/20 16:24:02 spz Exp $

 - Fixes CVE-2018-10754

--- ncurses/tinfo/parse_entry.c.orig	2018-10-09 21:41:29.020445746 +0000
+++ ncurses/tinfo/parse_entry.c
@@ -543,11 +543,12 @@ _nc_parse_entry(ENTRY * entryp, int lite
		 * Otherwise, look for a base entry that will already
		 * have picked up defaults via translation.
		 */
-		for (i = 0; i < entryp->nuses; i++)
-		    if (!strchr((char *) entryp->uses[i].name, '+'))
-			has_base_entry = TRUE;
+		for (i = 0; i < entryp->nuses; i++) {
+		  if (entryp->uses[i].name != 0
+		      && !strchr(entryp->uses[i].name, '+'))
+		    has_base_entry = TRUE;
+		}
	    }
-
	    postprocess_termcap(&entryp->tterm, has_base_entry);
	} else
	    postprocess_terminfo(&entryp->tterm);
