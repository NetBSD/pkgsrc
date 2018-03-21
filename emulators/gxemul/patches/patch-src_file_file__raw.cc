$NetBSD: patch-src_file_file__raw.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/file/file_raw.cc.orig	2014-08-17 08:45:10.000000000 +0000
+++ src/file/file_raw.cc
@@ -111,11 +111,11 @@ static void file_load_raw(struct machine
 		vaddr += len;
 	}
 
-	debug("RAW: 0x%"PRIx64" bytes @ 0x%08"PRIx64,
+	debug("RAW: 0x%" PRIx64 " bytes @ 0x%08" PRIx64,
 	    (uint64_t) (ftello(f) - skip), (uint64_t) loadaddr);
 
 	if (skip != 0)
-		debug(" (0x%"PRIx64" bytes of header skipped)",
+		debug(" (0x%" PRIx64 " bytes of header skipped)",
 		    (uint64_t) skip);
 
 	debug("\n");
@@ -126,4 +126,3 @@ static void file_load_raw(struct machine
 
 	n_executables_loaded ++;
 }
-
