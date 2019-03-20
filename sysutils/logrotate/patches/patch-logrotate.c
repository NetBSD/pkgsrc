$NetBSD: patch-logrotate.c,v 1.4 2019/03/20 10:34:10 he Exp $

Fix the running of scripts:
 * the "-c" option to "sh" causes subsequent args to not be passed
   to the script (oops!)
 * the "logrotate_script" arg ends up as arg1, not arg0 of the script,
   and is not documented, so get rid of it

--- logrotate.c.orig	2018-10-05 15:01:21.000000000 +0000
+++ logrotate.c
@@ -451,7 +451,7 @@ static int runScript(struct logInfo *log
                 exit(1);
             }
         }
-        execl("/bin/sh", "sh", "-c", script, "logrotate_script", logfn, logrotfn, (char *) NULL);
+        execl("/bin/sh", "sh", script, logfn, logrotfn, (char *) NULL);
         exit(1);
     }
 
