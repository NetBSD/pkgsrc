$NetBSD: patch-src_imap_imap-client.h,v 1.1 2017/01/17 15:39:40 wiz Exp $

Include sys/time.h for struct timeval.

--- src/imap/imap-client.h.orig	2016-12-03 17:13:21.000000000 +0000
+++ src/imap/imap-client.h
@@ -3,6 +3,7 @@
 
 #include "imap-commands.h"
 #include "message-size.h"
+#include <sys/time.h>
 
 #define CLIENT_COMMAND_QUEUE_MAX_SIZE 4
 /* Maximum number of CONTEXT=SEARCH UPDATEs. Clients probably won't need more
