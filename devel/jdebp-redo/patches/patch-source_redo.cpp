$NetBSD: patch-source_redo.cpp,v 1.2 2025/02/28 16:34:36 schmonz Exp $

Avoid CONFLICTS with other redo implementations.

--- source/redo.cpp.orig	2019-05-09 23:12:40.000000000 +0000
+++ source/redo.cpp
@@ -1221,13 +1221,16 @@ redo_main ( const char * prog, int argc,
 	putenv(gnulevelbuf);
 	putenv(bsdlevelbuf);
 
-	if (0 == std::strcmp(prog, "redo-ifcreate"))
+	if (0 == std::strcmp(prog, "redo-ifcreate")
+	||  0 == std::strcmp(prog, "jdebp-redo-ifcreate"))
 		return redo_ifcreate(prog, filev) ? EXIT_SUCCESS : EXIT_FAILURE;
 	else
-	if (0 == std::strcmp(prog, "redo-ifchange"))
+	if (0 == std::strcmp(prog, "redo-ifchange")
+	||  0 == std::strcmp(prog, "jdebp-redo-ifchange"))
 		return redo_ifchange(prog, meta_depth, filev) ? EXIT_SUCCESS : EXIT_FAILURE;
 	else
-	if (0 == std::strcmp(prog, "redo")) {
+	if (0 == std::strcmp(prog, "redo")
+	||  0 == std::strcmp(prog, "jdebp-redo")) {
 		mkdir(".redo", 0777);
 		return redo(true, prog, meta_depth, filev) ? EXIT_SUCCESS : EXIT_FAILURE;
 	} else
@@ -1283,7 +1286,8 @@ main ( int argc, const char * argv[] )
 {
 	const char * prog(basename_of(argv[0]));
 
-	if (0 == std::strcmp(prog, "cubehash"))
+	if (0 == std::strcmp(prog, "cubehash")
+	||  0 == std::strcmp(prog, "jdebp-cubehash"))
 		return cubehash_main(prog, argc, argv);
 	else
 		return redo_main(prog, argc, argv);
