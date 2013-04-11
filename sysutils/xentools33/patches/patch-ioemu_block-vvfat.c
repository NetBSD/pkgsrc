$NetBSD: patch-ioemu_block-vvfat.c,v 1.1 2013/04/11 19:57:53 joerg Exp $

--- ioemu/block-vvfat.c.orig	2013-03-28 16:52:33.000000000 +0000
+++ ioemu/block-vvfat.c
@@ -175,7 +175,7 @@ static inline int array_roll(array_t* ar
     return 0;
 }
 
-inline int array_remove_slice(array_t* array,int index, int count)
+static inline int array_remove_slice(array_t* array,int index, int count)
 {
     assert(index >=0);
     assert(count > 0);
