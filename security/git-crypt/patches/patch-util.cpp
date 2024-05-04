$NetBSD: patch-util.cpp,v 1.2 2024/05/04 11:07:17 leot Exp $

Keep the C++ streams synchronized to the standard C streams on NetBSD otherwise
it is not possible to read via std::cin.

Related to PR lib/58206.

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
