$NetBSD: patch-lib_mp4_udta.c,v 1.2 2017/09/25 22:30:06 joerg Exp $

Fix return type. we're not returning anything.

--- lib/mp4/udta.c.orig	2001-08-30 16:23:13.000000000 +0000
+++ lib/mp4/udta.c
@@ -38,7 +38,7 @@ int quicktime_udta_delete(quicktime_udta
 	return 0;
 }
 
-int quicktime_udta_dump(quicktime_udta_t *udta)
+void quicktime_udta_dump(quicktime_udta_t *udta)
 {
 	printf(" user data (udta)\n");
 	if(udta->copyright_len) printf("  copyright -> %s\n", udta->copyright);
@@ -64,17 +64,17 @@ int quicktime_read_udta(quicktime_t *fil
 
 		quicktime_atom_read_header(file, &leaf_atom);
 		
-		if(quicktime_atom_is(&leaf_atom, "©cpy"))
+		if(quicktime_atom_is(&leaf_atom, "\xa9""cpy"))
 		{
 			result += quicktime_read_udta_string(file, &(udta->copyright), &(udta->copyright_len));
 		}
 		else
-		if(quicktime_atom_is(&leaf_atom, "©nam"))
+		if(quicktime_atom_is(&leaf_atom, "\xa9nam"))
 		{
 			result += quicktime_read_udta_string(file, &(udta->name), &(udta->name_len));
 		}
 		else
-		if(quicktime_atom_is(&leaf_atom, "©inf"))
+		if(quicktime_atom_is(&leaf_atom, "\xa9inf"))
 		{
 			result += quicktime_read_udta_string(file, &(udta->info), &(udta->info_len));
 		}
@@ -88,7 +88,7 @@ int quicktime_read_udta(quicktime_t *fil
 	return result;
 }
 
-int quicktime_write_udta(quicktime_t *file, quicktime_udta_t *udta)
+void quicktime_write_udta(quicktime_t *file, quicktime_udta_t *udta)
 {
 	quicktime_atom_t atom, subatom;
 
@@ -112,21 +112,21 @@ int quicktime_write_udta(quicktime_t *fi
 
 	if(udta->copyright_len)
 	{
-		quicktime_atom_write_header(file, &subatom, "©cpy");
+		quicktime_atom_write_header(file, &subatom, "\xa9""cpy");
 		quicktime_write_udta_string(file, udta->copyright, udta->copyright_len);
 		quicktime_atom_write_footer(file, &subatom);
 	}
 
 	if(udta->name_len && !file->use_mp4)
 	{
-		quicktime_atom_write_header(file, &subatom, "©nam");
+		quicktime_atom_write_header(file, &subatom, "\xa9nam");
 		quicktime_write_udta_string(file, udta->name, udta->name_len);
 		quicktime_atom_write_footer(file, &subatom);
 	}
 
 	if(udta->info_len && !file->use_mp4)
 	{
-		quicktime_atom_write_header(file, &subatom, "©inf");
+		quicktime_atom_write_header(file, &subatom, "\xa9inf");
 		quicktime_write_udta_string(file, udta->info, udta->info_len);
 		quicktime_atom_write_footer(file, &subatom);
 	}
