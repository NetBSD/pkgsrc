$NetBSD: patch-music2_nwatowav.cc,v 1.1 2026/03/04 10:27:19 tsutsui Exp $

- appease -Wwrite-strings warnings

--- music2/nwatowav.cc.orig	2026-03-03 21:00:34.951069159 +0000
+++ music2/nwatowav.cc
@@ -626,7 +626,7 @@ int main(int argc, char** argv) {
 	if (strstr(argv[1], ".nwk") != 0 || strstr(argv[1], ".ovk") != 0) {
 		bool is_ovk;
 		int headblk_sz;
-		char* out_ext;
+		const char* out_ext;
 
 		char* outpath = new char[strlen(argv[1])+10];
 		char buf[1024];
