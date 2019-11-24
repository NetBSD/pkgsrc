$NetBSD: patch-xymonnet_xymonnet.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8078/
RPC buffer calculation on snprintf taking improper sizeof (Thanks, Tom Schmidt)

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- xymonnet/xymonnet.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ xymonnet/xymonnet.c
@@ -56,6 +56,7 @@ extern struct rpcent *getrpcbyname(char 
 #include "ldaptest.h"
 
 #define DEFAULT_PING_CHILD_COUNT 1
+#define MSGBUFSIZE 4096
 
 char *reqenv[] = {
 	"NONETPAGE",
@@ -1310,9 +1310,11 @@ int finish_ping_service(service_t *servi
 						pingcmd, WEXITSTATUS(pingstatus));
 		}
 
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 		/* Ignore gcc warnings about truncating filenames when adding a number */
 		#pragma GCC diagnostic push
 		#pragma GCC diagnostic ignored "-Wformat-truncation"
+#endif  // __GNUC__
 
 		/* Open the new ping result file */
 		snprintf(fn, sizeof(fn), "%s.%02d", pinglog, i);
@@ -1336,7 +1338,9 @@ int finish_ping_service(service_t *servi
 			if (errfd) fclose(errfd);
 		}
 		if (!debug) unlink(fn);
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 		#pragma GCC diagnostic pop
+#endif  // __GNUC__
 
 		if (failed) {
 			/* Flag all ping tests as "undecided" */
@@ -1848,7 +1849,7 @@ void send_rpcinfo_results(service_t *ser
 	char		*msgbuf;
 	char		causetext[1024];
 
-	msgbuf = (char *)malloc(4096);
+	msgbuf = (char *)malloc(MSGBUFSIZE);
 
 	for (t=service->items; (t); t = t->next) {
 		char *wantedrpcsvcs = NULL;
@@ -1904,7 +1905,7 @@ void send_rpcinfo_results(service_t *ser
 					snprintf(msgline, sizeof(msgline), "&%s Unknown RPC service %s\n",
 						colorname(COL_RED), rpcsvc);
 				}
-				strncat(msgbuf, msgline, (sizeof(msgbuf) - strlen(msgbuf)));
+				strncat(msgbuf, msgline, (MSGBUFSIZE - strlen(msgbuf)));
 
 				rpcsvc = strtok(NULL, ",");
 			}
