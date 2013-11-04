$NetBSD: patch-hdrs.c,v 1.1 2013/11/04 15:34:38 christos Exp $

bump limits higher: XXX these all need to be bounded to avoid DoS from
specially crafted error messages

--- hdrs.c	2013-11-04 10:24:04.000000000 -0500
+++ hdrs.c	2013-11-04 10:28:09.000000000 -0500
@@ -383,8 +383,8 @@
     static char		buf[HDRSIZ];
     register char	*p, *p2, *b;
     int			len, do_pad = FALSE, val, pad, got_dot, isauthor = 0, n;
-    char from[HDRSIZ], subject[256], date[64], lines[16];
-    char to[256], addr[256], name[256], user[256], status[4];
+    char from[HDRSIZ], subject[512], date[64], lines[16];
+    char to[512], addr[512], name[512], user[512], status[4];
     char Day[3], Mon[4], Tm[8], Yr[5], Wkday[4], Zone[8], *date_p;
 
     buf[0] = 0;
