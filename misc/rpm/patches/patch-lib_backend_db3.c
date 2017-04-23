$NetBSD: patch-lib_backend_db3.c,v 1.3 2017/04/23 08:18:15 adam Exp $

Add missing include.

--- lib/backend/db3.c.orig	2017-02-16 09:40:09.000000000 +0000
+++ lib/backend/db3.c
@@ -7,6 +7,7 @@ static int _debug = 1;	/* XXX if < 0 deb
 #include "system.h"
 
 #include <errno.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include <popt.h>
 #include <db.h>
