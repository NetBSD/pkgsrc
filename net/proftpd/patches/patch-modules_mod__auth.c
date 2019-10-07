$NetBSD: patch-modules_mod__auth.c,v 1.1 2019/10/07 19:29:47 christos Exp $

Add packet filter

--- modules/mod_auth.c.orig	2017-04-09 22:31:02.000000000 -0400
+++ modules/mod_auth.c	2019-10-07 15:10:42.316419545 -0400
@@ -28,6 +28,7 @@
 
 #include "conf.h"
 #include "privs.h"
+#include "pfilter.h"
 
 #ifdef HAVE_USERSEC_H
 # include <usersec.h>
@@ -97,6 +98,8 @@
     _("Login timeout (%d %s): closing control connection"), TimeoutLogin,
     TimeoutLogin != 1 ? "seconds" : "second");
 
+  pfilter_notify(1);
+
   /* It's possible that any listeners of this event might terminate the
    * session process themselves (e.g. mod_ban).  So write out that the
    * TimeoutLogin has been exceeded to the log here, in addition to the
@@ -1095,6 +1098,7 @@
         pr_memscrub(pass, strlen(pass));
       }
 
+      pfilter_notify(1);
       pr_log_auth(PR_LOG_NOTICE, "SECURITY VIOLATION: Root login attempted");
       return 0;
     }
@@ -1952,6 +1956,7 @@
   return 1;
 
 auth_failure:
+  pfilter_notify(1);
   if (pass)
     pr_memscrub(pass, strlen(pass));
   session.user = session.group = NULL;
