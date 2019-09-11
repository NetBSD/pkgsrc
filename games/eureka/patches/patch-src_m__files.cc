$NetBSD: patch-src_m__files.cc,v 1.1 2019/09/11 16:26:17 micha Exp $

Add placeholder for pkgsrc DOOMEADDIR to beginning of search list.

--- src/m_files.cc.orig	2018-06-23 11:29:07.000000000 +0000
+++ src/m_files.cc
@@ -721,6 +721,7 @@ static const char * SearchForIWAD(const 
 		"c:/doom2",
 		"c:/doom95",
 #else
+		"PKGSRC_DOOMWADDIR",
 		"/usr/share/games/doom",
 		"/usr/share/doom",
 		"/usr/local/share/games/doom",
