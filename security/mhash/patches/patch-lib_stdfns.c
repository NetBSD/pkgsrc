$NetBSD: patch-lib_stdfns.c,v 1.1 2015/06/18 06:17:33 dholland Exp $

Avoid returning expressions of type void.

--- lib/stdfns.c~	2015-06-18 06:08:36.000000000 +0000
+++ lib/stdfns.c
@@ -222,7 +222,8 @@ mutils_memcpy(void *dest, __const void *
 	if ((n < 16) || ((mutils_word32)ptr1 & 0x3) || ((mutils_word32)ptr2 
 & 0x3))
 	{
-		return mutils_memcpy8(ptr2, ptr1, n);
+		mutils_memcpy8(ptr2, ptr1, n);
+		return;
 	}
 
 	words = n >> 2;
