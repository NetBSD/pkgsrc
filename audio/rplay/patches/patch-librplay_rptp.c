$NetBSD: patch-librplay_rptp.c,v 1.1 2018/02/20 08:35:52 dholland Exp $

Use ctype.h correctly.

--- librplay/rptp.c~	1999-03-10 07:57:56.000000000 +0000
+++ librplay/rptp.c
@@ -44,6 +44,7 @@
 #else
 #include <varargs.h>
 #endif
+#include <ctype.h>
 #include <errno.h>
 
 int rptp_errno = RPTP_ERROR_NONE;
@@ -574,9 +575,9 @@ rptp_parse(response, name)
 	while (p && *p)
 	{
 	    /* Skip white-space. */
-	    if (isspace(*p))
+	    if (isspace((unsigned char)*p))
 	    {
-		for (p++; isspace(*p); p++) ;
+		for (p++; isspace((unsigned char)*p); p++) ;
 		continue;
 	    }
 
