$NetBSD: patch-src_misc.c,v 1.1 2020/07/13 13:12:09 kim Exp $

Fix day-of-month format so that strftime(3) will recognize it.

--- src/misc.c.orig	2020-05-03 11:05:50.000000000 +0000
+++ src/misc.c	2020-07-13 13:05:57.180120719 +0000
@@ -42,7 +42,7 @@ date(uintmax_t lclock)
   if (lclock_last != lclock)
   {
     lclock_last = lclock;  /* Cache value to avoid repetitive strftime() calls. */
-    strftime(buf, sizeof(buf), "%A %B %-e %Y -- %T %z", localtime((time_t *)&lclock));
+    strftime(buf, sizeof(buf), "%A %B %e %Y -- %T %z", localtime((time_t *)&lclock));
   }
 
   return buf;
@@ -90,7 +90,7 @@ date_ctime(uintmax_t lclock)
   if (lclock_last != lclock)
   {
     lclock_last = lclock;  /* Cache value to avoid repetitive strftime() calls. */
-    strftime(buf, sizeof(buf), "%a %b %-e %T %Y", localtime((time_t *)&lclock));
+    strftime(buf, sizeof(buf), "%a %b %e %T %Y", localtime((time_t *)&lclock));
   }
 
   return buf;
