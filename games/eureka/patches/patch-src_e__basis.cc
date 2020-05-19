$NetBSD: patch-src_e__basis.cc,v 1.2 2020/05/19 16:54:04 micha Exp $

Avoid sys/time.h SEC pollution.
https://sourceforge.net/p/eureka-editor/tickets/44/

--- src/e_basis.cc.orig	2020-02-14 01:04:52.000000000 +0000
+++ src/e_basis.cc
@@ -1197,16 +1197,16 @@ static void ChecksumVertex(crc32_c& crc,
 	crc += V->raw_y;
 }
 
-static void ChecksumSector(crc32_c& crc, const Sector * SEC)
+static void ChecksumSector(crc32_c& crc, const Sector * sect)
 {
-	crc += SEC->floorh;
-	crc += SEC->ceilh;
-	crc += SEC->light;
-	crc += SEC->type;
-	crc += SEC->tag;
+	crc += sect->floorh;
+	crc += sect->ceilh;
+	crc += sect->light;
+	crc += sect->type;
+	crc += sect->tag;
 
-	crc += SEC->FloorTex();
-	crc += SEC->CeilTex();
+	crc += sect->FloorTex();
+	crc += sect->CeilTex();
 }
 
 static void ChecksumSideDef(crc32_c& crc, const SideDef * S)
