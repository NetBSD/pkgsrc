$NetBSD: patch-src_astyle__main.cpp,v 1.4 2018/09/01 20:35:22 bsiegert Exp $

PATH_MAX is no longer defined in whatever header files were already included.

--- src/astyle_main.cpp.orig	2018-01-11 17:18:19.000000000 +0000
+++ src/astyle_main.cpp
@@ -50,6 +50,7 @@
 	#include <dirent.h>
 	#include <unistd.h>
 	#include <sys/stat.h>
+	#include <limits.h>	// for PATH_MAX
 	#ifdef __VMS
 		#include <unixlib.h>
 		#include <rms.h>
