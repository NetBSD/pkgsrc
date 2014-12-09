$NetBSD: patch-src_pepack.c,v 1.2 2014/12/09 14:37:06 khorben Exp $

Fixed the path to userdb.txt (see pkg/49458)

--- src/pepack.c.orig	2013-12-27 10:39:49.000000000 +0000
+++ src/pepack.c
@@ -21,6 +21,13 @@
 
 #include "common.h"
 
+#ifndef PREFIX
+# define PREFIX "/usr"
+#endif
+#ifndef DATADIR
+# define DATADIR PREFIX "/share"
+#endif
+
 #define PROGRAM "pepack"
 #define MAX_SIG_SIZE 2048
 
@@ -133,7 +140,7 @@ static bool loaddb(FILE **fp, const opti
 	*fp = fopen(dbfile, "r");	
 	if (!*fp) {
 		// TODO(jweyrich): This might change - Should we use a config.h with a constant from $(SHAREDIR)?
-		*fp = fopen("/usr/share/pev/userdb.txt", "r");
+		*fp = fopen(DATADIR "/pev/userdb.txt", "r");
 	}
 
 	return *fp != NULL;
