$NetBSD: patch-lib_backend_db3.c,v 1.1 2013/09/15 12:32:22 joerg Exp $

--- lib/backend/db3.c.orig	2013-09-14 20:59:12.000000000 +0000
+++ lib/backend/db3.c
@@ -7,6 +7,7 @@ static int _debug = 1;	/* XXX if < 0 deb
 #include "system.h"
 
 #include <errno.h>
+#include <signal.h>
 #include <sys/wait.h>
 
 #include <rpm/rpmtypes.h>
