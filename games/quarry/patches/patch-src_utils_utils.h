$NetBSD: patch-src_utils_utils.h,v 1.1 2012/11/16 00:50:40 joerg Exp $

--- src/utils/utils.h.orig	2012-11-15 15:09:27.000000000 +0000
+++ src/utils/utils.h
@@ -448,7 +448,7 @@ void		association_list_item_dispose (Ass
 							 (notch)))
 
 
-inline char *	association_list_find_association (AssociationList *list,
+char *	association_list_find_association (AssociationList *list,
 						   const char *key);
 
 
