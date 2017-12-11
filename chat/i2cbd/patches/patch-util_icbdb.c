$NetBSD: patch-util_icbdb.c,v 1.1 2017/12/11 19:00:32 spz Exp $

pacify compiler warnings

--- util/icbdb.c.orig	2003-10-24 20:52:24.000000000 +0000
+++ util/icbdb.c
@@ -20,7 +20,7 @@ int
 main (int argc, char **argv)
 {
 	int	c, initflag = 0, catflag = 0, delflag = 0, findflag = 0;
-	char	*dbname, *uname;
+	char	*dbname, *uname = NULL;
 	DB	*db;
 	DBT	key, data;
 
