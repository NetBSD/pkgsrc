$NetBSD: patch-src_ui__replace.cc,v 1.2 2020/05/19 16:54:04 micha Exp $

Avoid sys/time.h SEC pollution.
https://sourceforge.net/p/eureka-editor/tickets/44/

--- src/ui_replace.cc.orig	2020-02-02 13:48:48.000000000 +0000
+++ src/ui_replace.cc
@@ -1514,18 +1514,18 @@ bool UI_FindAndReplace::Match_LineDef(in
 
 bool UI_FindAndReplace::Match_Sector(int idx)
 {
-	const Sector *SEC = Sectors[idx];
+	const Sector *sect = Sectors[idx];
 
-	if (! Filter_Tag(SEC->tag))
+	if (! Filter_Tag(sect->tag))
 		return false;
 
 	const char *pattern = find_match->value();
 
 	if (!filter_toggle->value() || o_floors->value())
-		if (Pattern_Match(SEC->FloorTex(), pattern))
+		if (Pattern_Match(sect->FloorTex(), pattern))
 			return true;
 
-	const char *ceil_tex = SEC->CeilTex();
+	const char *ceil_tex = sect->CeilTex();
 
 	if (!filter_toggle->value() || (!is_sky(ceil_tex) && o_ceilings->value())
 								|| ( is_sky(ceil_tex) && o_skies->value()) )
@@ -1552,15 +1552,15 @@ bool UI_FindAndReplace::Match_LineType(i
 
 bool UI_FindAndReplace::Match_SectorType(int idx)
 {
-	const Sector *SEC = Sectors[idx];
+	const Sector *sect = Sectors[idx];
 
 	int mask = (Features.gen_sectors == 2) ? 255 :
 				(Features.gen_sectors) ? 31 : 65535;
 
-	if (! find_numbers->get(SEC->type & mask))
+	if (! find_numbers->get(sect->type & mask))
 		return false;
 
-	if (! Filter_Tag(SEC->tag))
+	if (! Filter_Tag(sect->tag))
 		return false;
 
 	return true;
@@ -1746,15 +1746,15 @@ void UI_FindAndReplace::Replace_LineDef(
 
 void UI_FindAndReplace::Replace_Sector(int idx, int new_tex)
 {
-	const Sector *SEC = Sectors[idx];
+	const Sector *sect = Sectors[idx];
 
 	const char *pattern = find_match->value();
 
 	if (!filter_toggle->value() || o_floors->value())
-		if (Pattern_Match(SEC->FloorTex(), pattern))
+		if (Pattern_Match(sect->FloorTex(), pattern))
 			BA_ChangeSEC(idx, Sector::F_FLOOR_TEX, new_tex);
 
-	const char *ceil_tex = SEC->CeilTex();
+	const char *ceil_tex = sect->CeilTex();
 
 	if (!filter_toggle->value() || (!is_sky(ceil_tex) && o_ceilings->value())
 								|| ( is_sky(ceil_tex) && o_skies->value()) )
