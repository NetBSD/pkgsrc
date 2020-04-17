$NetBSD: patch-common_CvsArgs.cpp,v 1.1 2020/04/17 00:21:56 joerg Exp $

--- common/CvsArgs.cpp.orig	2020-04-16 19:55:52.305420243 +0000
+++ common/CvsArgs.cpp
@@ -198,7 +198,7 @@ void CvsArgs::print(const char *indirect
 	{
 		CStr newarg;
 		newarg = argv[i];
-		bool hasLF = strchr(newarg, '\n') != 0L;
+		bool hasLF = strchr((const char *)newarg, '\n') != 0L;
 		size_t len = newarg.length();
 
 		if(len > MAX_PRINT_ARG)
@@ -207,7 +207,7 @@ void CvsArgs::print(const char *indirect
 		if(hasLF)
 			newarg = expandLF(newarg, buf);
 
-		bool hasSpace = strchr(newarg, ' ') != 0L;
+		bool hasSpace = strchr((const char *)newarg, ' ') != 0L;
 		if(hasSpace)
 			cvs_out("\"");
 		cvs_outstr(newarg, newarg.length());
