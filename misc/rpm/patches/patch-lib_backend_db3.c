$NetBSD: patch-lib_backend_db3.c,v 1.2 2015/03/15 05:34:56 ryoon Exp $

--- lib/backend/db3.c.orig	2014-06-30 08:47:13.000000000 +0000
+++ lib/backend/db3.c
@@ -7,6 +7,7 @@ static int _debug = 1;	/* XXX if < 0 deb
 #include "system.h"
 
 #include <errno.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include <db.h>
 
