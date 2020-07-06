$NetBSD: patch-source_redo.cpp,v 1.1 2020/07/06 15:16:49 schmonz Exp $

Avoid CONFLICTS with other redo implementations.

--- source/redo.cpp.orig	2017-04-18 18:09:52.000000000 +0000
+++ source/redo.cpp
@@ -1373,6 +1373,7 @@ main ( int argc, const char * argv[] )
 	putenv(levelbuf);
 
 	if (0 == std::strcmp(prog, "redo-ifcreate")
+	||  0 == std::strcmp(prog, "jdebp-redo-ifcreate")
 #if defined(__OS2__) || defined(__WIN32__) || defined(__NT__)
 	||  0 == stricmp(prog, "redo-ifcreate.exe")
 #endif
@@ -1380,6 +1381,7 @@ main ( int argc, const char * argv[] )
 		return redo_ifcreate(prog, filev) ? EXIT_SUCCESS : EXIT_FAILURE;
 	else
 	if (0 == std::strcmp(prog, "redo-ifchange")
+	||  0 == std::strcmp(prog, "jdebp-redo-ifchange")
 #if defined(__OS2__) || defined(__WIN32__) || defined(__NT__)
 	||  0 == stricmp(prog, "redo-ifchange.exe")
 #endif
@@ -1390,6 +1392,7 @@ main ( int argc, const char * argv[] )
 	}
 	else
 	if (0 == std::strcmp(prog, "redo")
+	||  0 == std::strcmp(prog, "jdebp-redo")
 #if defined(__OS2__) || defined(__WIN32__) || defined(__NT__)
 	||  0 == stricmp(prog, "redo.exe")
 #endif
@@ -1400,6 +1403,7 @@ main ( int argc, const char * argv[] )
 		return r ? EXIT_SUCCESS : EXIT_FAILURE;
 	}
 	if (0 == std::strcmp(prog, "cubehash")
+	||  0 == std::strcmp(prog, "jdebp-cubehash")
 #if defined(__OS2__) || defined(__WIN32__) || defined(__NT__)
 	||  0 == stricmp(prog, "cubehash.exe")
 #endif
