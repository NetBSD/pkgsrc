$NetBSD: patch-sql_tztime.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/tztime.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/tztime.cc
@@ -2643,7 +2643,7 @@ main(int argc, char **argv)
   if (TYPE_SIGNED(time_t))
   {
     t= -100;
-    localtime_negative= test(localtime_r(&t, &tmp) != 0);
+    localtime_negative= my_test(localtime_r(&t, &tmp) != 0);
     printf("localtime_r %s negative params \
            (time_t=%d is %d-%d-%d %d:%d:%d)\n",
            (localtime_negative ? "supports" : "doesn't support"), (int)t,
