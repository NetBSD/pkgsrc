$NetBSD: patch-src_os_pl-files.c,v 1.1 2018/12/10 14:59:50 leot Exp $

Avoid overlapping `src' and `dst' in strcpy(3).

This is reproducible via:

 % ln -s `which swi-prolog` swipl-l
 % ./swipl-l

...and was also triggered similarly as part of building swi-prolog-packages.

--- src/os/pl-files.c.orig	2018-01-12 12:04:38.000000000 +0000
+++ src/os/pl-files.c
@@ -273,6 +273,7 @@ ReadLink(const char *f, char *buf)
 static char *
 DeRefLink1(const char *f, char *lbuf)
 { char buf[MAXPATHLEN];
+  char tmpbuf[MAXPATHLEN];
   char *l;
 
   if ( (l=ReadLink(f, buf)) )
@@ -282,13 +283,14 @@ DeRefLink1(const char *f, char *lbuf)
     } else
     { char *q;
 
-      strcpy(lbuf, f);
-      q = &lbuf[strlen(lbuf)];
-      while(q>lbuf && q[-1] != '/')
+      strcpy(tmpbuf, f);
+      q = &tmpbuf[strlen(tmpbuf)];
+      while(q>tmpbuf && q[-1] != '/')
 	q--;
       strcpy(q, l);
 
-      canonicaliseFileName(lbuf);
+      canonicaliseFileName(tmpbuf);
+      strcpy(lbuf, tmpbuf);
 
       return lbuf;
     }
