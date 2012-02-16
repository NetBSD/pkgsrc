$NetBSD: patch-incoming_login.c,v 1.2 2012/02/16 17:32:45 hans Exp $

--- incoming/login.c.orig	2011-11-25 20:00:14.000000000 +0000
+++ incoming/login.c
@@ -47,6 +47,7 @@ static char copyright[] =
 #include <stdio.h>
 #include <fcntl.h>
 #include <syslog.h>
+#include <stdlib.h>
 #include "mcap.h"
 #include "ttio.h"
 
@@ -70,7 +71,9 @@ void do_login (name, ttyName)
   /* At this point, we have carrier, so it's time to log the login... */
   strncpy (utRec.ut_line, ttyName, UT_LINESIZE);
   strncpy (utRec.ut_name, name, UT_NAMESIZE);
+#ifndef __sun
   utRec.ut_host [0] = 0;
+#endif
 
   loginout ();
 }
