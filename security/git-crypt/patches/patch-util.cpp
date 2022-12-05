$NetBSD: patch-util.cpp,v 1.1 2022/12/05 21:57:58 nikita Exp $

Keep the C++ streams synchronized to the standard C streams on NetBSD otherwise
it is not possible to read via std::cin.

XXX: Why?

--- util.cpp.orig	2017-11-26 18:24:03.000000000 +0000
+++ util.cpp
@@ -141,7 +141,9 @@ static void	init_std_streams_platform ()
 void		init_std_streams ()
 {
 	// The following two lines are essential for achieving good performance:
+#ifndef __NetBSD__
 	std::ios_base::sync_with_stdio(false);
+#endif
 	std::cin.tie(0);
 
 	std::cin.exceptions(std::ios_base::badbit);
