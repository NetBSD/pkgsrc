$NetBSD: patch-secblock.h,v 1.1 2012/04/17 17:46:31 joerg Exp $

--- secblock.h.orig	2012-04-17 15:36:29.000000000 +0000
+++ secblock.h
@@ -94,7 +94,7 @@ public:
 
 	pointer allocate(size_type n, const void * = NULL)
 	{
-		CheckSize(n);
+		this->CheckSize(n);
 		if (n == 0)
 			return NULL;
 
