$NetBSD: patch-main.c,v 1.4 2019/01/15 09:49:40 wiz Exp $

main.c:340:1: error: function 'usage' could be declared with attribute 'noreturn' [-Werror,-Wmissing-noreturn]

--- main.c.orig	2018-09-20 12:31:51.000000000 +0000
+++ main.c
@@ -335,6 +335,7 @@ find_cmd(const char *arg)
 	return -1;
 }
 
+__attribute__((noreturn))
 static void
 usage(int status)
 {
