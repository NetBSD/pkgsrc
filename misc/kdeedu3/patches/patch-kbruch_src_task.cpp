$NetBSD: patch-kbruch_src_task.cpp,v 1.1 2016/04/14 11:11:09 jperkin Exp $

Avoid ambiguous overloaded call errors.

--- kbruch/src/task.cpp.orig	2007-05-14 07:38:52.000000000 +0000
+++ kbruch/src/task.cpp
@@ -72,7 +72,7 @@ void task::create_task(unsigned int pmax
 		/* later we must be able to find a main denominator;
 		 * so 2 ^ max_product_length couldn't be bigger than the max. denominator */
 	}
-	while ((unsigned int) pow(2, max_product_length) > pmax_md);
+	while ((unsigned int) pow((double)2, (double)max_product_length) > pmax_md);
 
 #ifdef DEBUG
 	kdDebug() << "2: max_product_length: " << max_product_length << endl;
