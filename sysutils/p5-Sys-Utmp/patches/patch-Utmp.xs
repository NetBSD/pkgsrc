$NetBSD: patch-Utmp.xs,v 1.1 2017/09/28 04:45:11 wiz Exp $

Fix build on NetBSD.
https://github.com/jonathanstowe/Sys-Utmp/issues/1

--- Utmp.xs.orig	2013-10-27 08:34:17.000000000 +0000
+++ Utmp.xs
@@ -57,11 +57,6 @@ static int ut_fd = -1;
 
 static char _ut_name[] = _PATH_UTMP;
 
-void utmpname(char *filename)
-{
-   strcpy(_ut_name, filename);
-}
-
 void setutent(void)
 {
     if (ut_fd < 0)
