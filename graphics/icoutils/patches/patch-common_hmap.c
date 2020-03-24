$NetBSD: patch-common_hmap.c,v 1.1 2020/03/24 06:29:40 rillig Exp $

hmap.c:77:30: error: array subscript has type 'char' [-Werror=char-subscripts]

https://savannah.nongnu.org/bugs/index.php?58033

--- common/hmap.c.orig	2012-05-03 23:14:50.000000000 +0000
+++ common/hmap.c
@@ -74,7 +74,7 @@ strcasehash(const char *str)
     uint32_t hash = 0;
 
     for (; *str != '\0'; str++)
-	hash = (hash << 5) - hash + tolower(*str);
+	hash = (hash << 5) - hash + tolower((unsigned char)*str);
 
     return hash;
 }
