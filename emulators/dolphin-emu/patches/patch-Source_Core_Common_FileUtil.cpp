$NetBSD: patch-Source_Core_Common_FileUtil.cpp,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/Common/FileUtil.cpp.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/Common/FileUtil.cpp
@@ -45,7 +45,7 @@
 #define S_ISDIR(m)  (((m)&S_IFMT) == S_IFDIR)
 #endif
 
-#if defined BSD4_4 || defined __FreeBSD__
+#if defined BSD4_4 || defined __FreeBSD__ || defined __NetBSD__
 #define stat64 stat
 #define fstat64 fstat
 #endif
