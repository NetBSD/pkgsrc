$NetBSD: patch-libiberty_simple-object-mach-o.c,v 1.1 2024/03/27 23:26:29 js Exp $

--- libiberty/simple-object-mach-o.c.orig	2024-03-27 16:20:30.299783020 +0000
+++ libiberty/simple-object-mach-o.c
@@ -1228,7 +1228,7 @@ simple_object_mach_o_write_segment (simp
       /* Swap the indices, if required.  */
 
       for (i = 0; i < (nsects_in * 4); ++i)
-	set_32 (&index[i], index[i]);
+	set_32 ((unsigned char *)&index[i], index[i]);
 
       sechdr_offset += sechdrsize;
 
