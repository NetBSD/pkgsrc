$NetBSD: patch-ncurses_tinfo_parse_entry.c,v 1.1 2025/06/22 11:13:07 kim Exp $

Cherry picked fix for CVE-2025-6141 from
https://invisible-island.net/archives/ncurses/6.5/ncurses-6.5-20250329.patch.gz

--- ncurses/tinfo/parse_entry.c.orig	2023-04-24 22:32:33.000000000 +0000
+++ ncurses/tinfo/parse_entry.c	2025-06-22 07:14:15.542701527 +0000
@@ -985,6 +985,8 @@
 	    bp = tp->Strings[from_ptr->nte_index];
 	    if (VALID_STRING(bp)) {
 		for (dp = buf2; *bp; bp++) {
+		    if ((size_t) (dp - buf2) >= (sizeof(buf2) - sizeof(TERMTYPE2)))
+			  break;
 		    if (bp[0] == '$' && bp[1] == '<') {
 			while (*bp && *bp != '>') {
 			    ++bp;
