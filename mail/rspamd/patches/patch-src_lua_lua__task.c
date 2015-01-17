$NetBSD: patch-src_lua_lua__task.c,v 1.1 2015/01/17 17:34:07 wiedi Exp $

tm_gmtoff is not a POSIX field
--- src/lua/lua_task.c.orig	2015-01-02 11:07:18.000000000 +0000
+++ src/lua/lua_task.c
@@ -1765,7 +1765,9 @@ lua_task_get_date (lua_State *L)
 
 				tt = tim;
 				localtime_r (&tt, &t);
+#if !defined(__sun)
 				t.tm_gmtoff = 0;
+#endif
 				t.tm_isdst = 0;
 				tim = mktime (&t);
 			}
