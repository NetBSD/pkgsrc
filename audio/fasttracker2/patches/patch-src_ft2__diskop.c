$NetBSD: patch-src_ft2__diskop.c,v 1.6 2019/08/02 16:54:10 fox Exp $

1. Added <sys/types.h> and <sys/stat.h> before the include of
   <fts.h>. While fts(3) is not yet standardized by POSIX, NetBSD
   contains an implementation that was expected to comply with the
   eventual standard, and fts(3) on NetBSD documents that the above
   includes are required. Resolves build failure on netbsd-8.
   
2. Added SunOS / SmartOS compatibility.

Note: Contacted the upstream author regarding the patch and awaiting a
reply. https://16-bits.org/ft2.php

--- src/ft2_diskop.c.orig	2019-06-20 21:20:34.000000000 +0000
+++ src/ft2_diskop.c
@@ -15,6 +15,8 @@
 #include <direct.h>
 #include <shlobj.h> // SHGetFolderPathW()
 #else
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <fts.h> // for fts_open() and stuff in recursiveDelete()
 #include <unistd.h>
 #include <dirent.h>
@@ -1395,6 +1397,10 @@ static int8_t findFirst(DirRec *searchRe
 	int64_t fSize;
 #endif
 
+#if defined(__sun) || defined(sun)
+	struct stat s;
+#endif
+
 	searchRec->nameU = NULL; // this one must be initialized
 
 #ifdef _WIN32
@@ -1422,9 +1428,19 @@ static int8_t findFirst(DirRec *searchRe
 		return LFF_SKIP;
 
 	searchRec->filesize = 0;
+
+#if defined(__sun) || defined(sun)
+	stat(fData->d_name, &s);
+	searchRec->isDir = (s.st_mode != S_IFDIR) ? true : false;
+#else
 	searchRec->isDir = (fData->d_type == DT_DIR) ? true : false;
+#endif
 
+#if defined(__sun) || defined(sun)
+	if (s.st_mode == S_IFLNK)
+#else
 	if (fData->d_type == DT_UNKNOWN || fData->d_type == DT_LNK)
+#endif
 	{
 		if (stat(fData->d_name, &st) == 0)
 		{
@@ -1488,9 +1504,19 @@ static int8_t findNext(DirRec *searchRec
 		return LFF_SKIP;
 
 	searchRec->filesize = 0;
+
+#if defined(__sun) || defined(sun)
+	stat(fData->d_name, &s);
+	searchRec->isDir = (s.st_mode != S_IFDIR) ? true : false;
+#else
 	searchRec->isDir = (fData->d_type == DT_DIR) ? true : false;
+#endif
 
+#if defined(__sun) || defined(sun)
+	if (s.st_mode == S_IFLNK)
+#else
 	if (fData->d_type == DT_UNKNOWN || fData->d_type == DT_LNK)
+#endif
 	{
 		if (stat(fData->d_name, &st) == 0)
 		{
