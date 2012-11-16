$NetBSD: patch-spunk_unixsrc_filesys.cc,v 1.1 2012/11/16 00:37:47 joerg Exp $

--- spunk/unixsrc/filesys.cc.orig	1996-11-07 18:06:58.000000000 +0000
+++ spunk/unixsrc/filesys.cc
@@ -42,10 +42,10 @@
 
 extern const char FileSysPathSep	= '/';	// Path separator
 extern const char FileSysListSep	= ':';	// Path list separator
-extern const FileSysMaxPath		= 255;	// Maximum path length
-extern const FileSysMaxDir		= 255;	// Maximum directory length
-extern const FileSysMaxName		= 255;	// Maximum file name length
-extern const FileSysMaxExt		= 255;	// Maximum extension length (including the dot)
+extern const int FileSysMaxPath		= 255;	// Maximum path length
+extern const int FileSysMaxDir		= 255;	// Maximum directory length
+extern const int FileSysMaxName		= 255;	// Maximum file name length
+extern const int FileSysMaxExt		= 255;	// Maximum extension length (including the dot)
 
 
 
