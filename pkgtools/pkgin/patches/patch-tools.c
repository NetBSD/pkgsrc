$NetBSD: patch-tools.c,v 1.1 2019/01/15 09:49:40 wiz Exp $

tools.c:107:28: error: format string is not a string literal [-Werror,-Wformat-nonliteral]

--- tools.c.orig	2018-09-20 12:31:51.000000000 +0000
+++ tools.c
@@ -96,6 +96,7 @@ trunc_str(char *str, char limit, int dir
 	}
 }
 
+__attribute__((__format__ (__printf__, 2, 3)))
 void
 do_log(const char *path, const char *fmt, ...)
 {
