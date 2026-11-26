$NetBSD: patch-Foundation_src_Path__UNIX.cpp,v 1.1 2026/11/26 10:25:52 nros Exp $

getexecname() returns "const char *"

--- Foundation/src/Path_UNIX.cpp.orig	2026-05-20 16:41:39.000000000 +0000
+++ Foundation/src/Path_UNIX.cpp
@@ -75,7 +75,7 @@ std::string PathImpl::selfImpl()
 	if (n > 0 && n < PATH_MAX)
 		path = buf;
 #elif POCO_OS == POCO_OS_SOLARIS
-	char * execName = getexecname();
+	const char * execName = getexecname();
 	if (execName)
 		path = execName;
 	else
