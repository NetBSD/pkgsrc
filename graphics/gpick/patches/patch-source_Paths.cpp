$NetBSD: patch-source_Paths.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/Paths.cpp.orig	2024-10-02 09:32:54.911598061 +0000
+++ source/Paths.cpp
@@ -36,7 +36,7 @@ struct PathException: std::runtime_error
 		std::runtime_error(message) {
 	}
 };
-#if BOOST_OS_LINUX != 0
+#if BOOST_OS_LINUX != 0 || BOOST_OS_BSD_NET != 0
 static std::string getExecutablePath() {
 	std::vector<char> buffer;
 	buffer.resize(4096);
