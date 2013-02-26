$NetBSD: patch-log.c,v 1.1 2013/02/26 11:26:03 joerg Exp $

--- log.c.orig	2013-02-25 16:47:16.000000000 +0000
+++ log.c
@@ -11,9 +11,7 @@ static char buf[1];
 static char num[FMT_ULONG];
 static stralloc line = {0};
 
-void log(event,addr)
-char *event;
-char *addr;
+void log(char *event, char *addr)
 {
   char ch;
   int fd;
