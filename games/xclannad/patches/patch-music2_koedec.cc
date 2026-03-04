$NetBSD: patch-music2_koedec.cc,v 1.1 2026/03/04 12:38:01 tsutsui Exp $

- fix possible NULL dereferences

--- music2/koedec.cc.orig	2008-08-31 09:52:12.000000000 +0000
+++ music2/koedec.cc
@@ -96,10 +96,15 @@ AvgKoeInfo AvgKoeCache::Find(int file_nu
 	if (it == cache.end()) {
 		/* 新たに head を作る */
 		char fname[100];
+		char *subdir = 0;
 		KoeType type = koe_unknown;
 		sprintf(fname, "z%03d.koe", file_number);
 		ARCINFO* arcinfo = file_searcher.Find(FILESEARCH::KOE,fname,".koe");
 		if (arcinfo == 0) {
+			sprintf(fname, "z%04d.koe", file_number);
+			arcinfo = file_searcher.Find(FILESEARCH::KOE,fname,".koe");
+		}
+		if (arcinfo == 0) {
 			type = koe_nwk;
 			sprintf(fname, "z%04d.nwk", file_number);
 			arcinfo = file_searcher.Find(FILESEARCH::KOE,fname,".nwk");
@@ -113,7 +118,15 @@ AvgKoeInfo AvgKoeCache::Find(int file_nu
 			DIRFILE* koedir = (DIRFILE*) file_searcher.MakeARCFILE((FILESEARCH::ARCTYPE)0, "koe");
 			sprintf(fname, "%04d", file_number);
 			koedir = new DIRFILE(koedir->SearchFile(fname));
+			if (koedir == 0) return info;
 			sprintf(fname, "z%04d%05d.ogg", file_number, index);
+			subdir = koedir->SearchFile(fname);
+			delete koedir;
+			koedir = 0;
+			if (subdir == 0) return info;
+			koedir = new DIRFILE(subdir);
+			delete[] subdir;
+			subdir = 0;
 			arcinfo = koedir->Find(fname, ".ogg");
 			delete koedir;
 			
