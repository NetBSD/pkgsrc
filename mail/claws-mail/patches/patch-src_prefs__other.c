$NetBSD: patch-src_prefs__other.c,v 1.1 2021/07/13 12:35:09 nia Exp $

--- src/prefs_other.c.orig	2021-07-10 08:47:08.000000000 +0000
+++ src/prefs_other.c
@@ -582,7 +582,7 @@ static void prefs_other_create_widget(Pr
 	PACK_CHECK_BUTTON (vbox2, checkbtn_askonfilter,
 			   _("Ask about account specific filtering rules when "
 			     "filtering manually"));
-	shred_binary = g_find_program_in_path("shred");
+	shred_binary = g_find_program_in_path("claws-mail-shred");
 	if (shred_binary) {
 		PACK_CHECK_BUTTON (vbox2, checkbtn_use_shred,
 				   _("Use secure file deletion if possible"));
