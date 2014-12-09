$NetBSD: patch-src_pepack.c,v 1.1 2014/12/09 13:26:40 khorben Exp $

Fixed the path to userdb.txt (see pkg/49458)

--- src/pepack.c.orig	2012-10-31 03:59:14.000000000 +0000
+++ src/pepack.c
@@ -21,6 +21,13 @@
 
 #include "pepack.h"
 
+#ifndef PREFIX
+# define PREFIX "/usr"
+#endif
+#ifndef DATADIR
+# define DATADIR PREFIX "/share"
+#endif
+
 struct options config;
 static int ind;
 
@@ -119,7 +126,7 @@ bool loaddb(FILE **fp)
 	*fp = fopen(dbfile, "r");	
 
 	if (!*fp)
-		*fp = fopen("/usr/share/pev/userdb.txt", "r");
+		*fp = fopen(DATADIR "/pev/userdb.txt", "r");
 
 	return (*fp != NULL);
 }
