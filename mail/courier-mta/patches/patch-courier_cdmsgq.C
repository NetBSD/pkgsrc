$NetBSD: patch-courier_cdmsgq.C,v 1.1 2013/04/29 21:22:17 joerg Exp $

--- courier/cdmsgq.C.orig	2013-04-28 14:54:36.000000000 +0000
+++ courier/cdmsgq.C
@@ -41,6 +41,7 @@
 #include	<vector>
 #include	<list>
 #include	<algorithm>
+#include	<functional>
 
 std::vector<msgq> msgq::queue;
 std::vector<msgq *> msgq::queuehashfirst, msgq::queuehashlast;
