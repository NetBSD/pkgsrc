$NetBSD: patch-mysys_my__copy.c,v 1.1 2013/04/29 21:16:56 joerg Exp $

--- mysys/my_copy.c.orig	2013-04-28 13:55:27.000000000 +0000
+++ mysys/my_copy.c
@@ -63,7 +63,7 @@ int my_copy(const char *from, const char
   from_file=to_file= -1;
   DBUG_ASSERT(!(MyFlags & (MY_FNABP | MY_NABP))); /* for my_read/my_write */
   if (MyFlags & MY_HOLD_ORIGINAL_MODES)		/* Copy stat if possible */
-    new_file_stat= test(my_stat((char*) to, &new_stat_buff, MYF(0)));
+    new_file_stat= my_test(my_stat((char*) to, &new_stat_buff, MYF(0)));
 
   if ((from_file=my_open(from,O_RDONLY | O_SHARE,MyFlags)) >= 0)
   {
