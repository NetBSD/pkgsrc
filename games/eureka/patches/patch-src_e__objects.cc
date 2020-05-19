$NetBSD: patch-src_e__objects.cc,v 1.2 2020/05/19 16:54:04 micha Exp $

Avoid sys/time.h SEC pollution.
https://sourceforge.net/p/eureka-editor/tickets/44/

--- src/e_objects.cc.orig	2020-02-02 13:45:57.000000000 +0000
+++ src/e_objects.cc
@@ -901,16 +901,16 @@ static void TransferThingProperties(int
 
 static void TransferSectorProperties(int src_sec, int dest_sec)
 {
-	const Sector * SEC = Sectors[src_sec];
+	const Sector * sect = Sectors[src_sec];
 
-	BA_ChangeSEC(dest_sec, Sector::F_FLOORH,    SEC->floorh);
-	BA_ChangeSEC(dest_sec, Sector::F_FLOOR_TEX, SEC->floor_tex);
-	BA_ChangeSEC(dest_sec, Sector::F_CEILH,     SEC->ceilh);
-	BA_ChangeSEC(dest_sec, Sector::F_CEIL_TEX,  SEC->ceil_tex);
+	BA_ChangeSEC(dest_sec, Sector::F_FLOORH,    sect->floorh);
+	BA_ChangeSEC(dest_sec, Sector::F_FLOOR_TEX, sect->floor_tex);
+	BA_ChangeSEC(dest_sec, Sector::F_CEILH,     sect->ceilh);
+	BA_ChangeSEC(dest_sec, Sector::F_CEIL_TEX,  sect->ceil_tex);
 
-	BA_ChangeSEC(dest_sec, Sector::F_LIGHT,  SEC->light);
-	BA_ChangeSEC(dest_sec, Sector::F_TYPE,   SEC->type);
-	BA_ChangeSEC(dest_sec, Sector::F_TAG,    SEC->tag);
+	BA_ChangeSEC(dest_sec, Sector::F_LIGHT,  sect->light);
+	BA_ChangeSEC(dest_sec, Sector::F_TYPE,   sect->type);
+	BA_ChangeSEC(dest_sec, Sector::F_TAG,    sect->tag);
 }
 
 
