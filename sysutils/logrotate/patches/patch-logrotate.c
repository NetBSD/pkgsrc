$NetBSD: patch-logrotate.c,v 1.3 2017/03/06 12:59:53 fhajny Exp $

Fixes GCC error:
"error: missing sentinel in function call [-Werror=format=]"

--- logrotate.c.orig	2016-11-30 13:07:15.000000000 +0000
+++ logrotate.c
@@ -440,7 +440,7 @@ static int runScript(struct logInfo *log
 				DOEXIT(1);
 			}
 		}
-		execl("/bin/sh", "sh", "-c", script, "logrotate_script", logfn, NULL);
+		execl("/bin/sh", "sh", "-c", script, "logrotate_script", logfn, (char *)NULL);
 		DOEXIT(1);
 	}
 
@@ -800,7 +800,7 @@ static int mailLog(struct logInfo *log,
 				DOEXIT(1);
 			}
 
-			execlp(uncompressCommand, uncompressCommand, NULL);
+			execlp(uncompressCommand, uncompressCommand, (char *)NULL);
 			DOEXIT(1);
 		}
 
