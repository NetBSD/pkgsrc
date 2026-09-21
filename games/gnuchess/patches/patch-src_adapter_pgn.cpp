$NetBSD: patch-src_adapter_pgn.cpp,v 1.1 2026/09/21 09:30:53 wiz Exp $

Fix ctype(3) usage.
Mailed to bug-gnu-chess mailing list on 2026-09-21.

--- src/adapter/pgn.cpp.orig	2026-09-21 08:50:11.609305395 +0000
+++ src/adapter/pgn.cpp
@@ -545,7 +545,7 @@ static void pgn_skip_blanks(pgn_t * pgn) {
 
       if (false) {
 
-      } else if (isspace(pgn->char_hack)) {
+      } else if (isspace((unsigned char)pgn->char_hack)) {
 
          // skip white space
 
