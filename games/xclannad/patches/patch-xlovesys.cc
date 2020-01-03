$NetBSD: patch-xlovesys.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

Use VL-PGothic instead of msgothic.ttc for the default TTF.

--- xlovesys.cc.orig	2008-01-06 05:17:14.000000000 +0000
+++ xlovesys.cc
@@ -61,7 +61,7 @@ int main(int argc, char *argv[]) {
 	AyuSysConfig config;
 	int opt = 0, end = 0, screenmode = 0;
 	char rootPath[1024]  = "/mnt/KEY/CLANNAD";
-	char font[1024]      = "msgothic.ttc";
+	char font[1024]      = "VL-PGothic-Regular.ttf";
 	Uint32 videoOptions  = SDL_HWSURFACE;
 
 	while(1) {
