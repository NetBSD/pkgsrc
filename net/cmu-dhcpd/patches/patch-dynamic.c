$NetBSD: patch-dynamic.c,v 1.1 2012/11/23 12:31:05 joerg Exp $

--- dynamic.c.orig	2012-11-21 16:07:58.000000000 +0000
+++ dynamic.c
@@ -67,6 +67,7 @@ SOFTWARE.
 #define MAXTOKENS		 256	/* Max tokens per line */
 #define MAXENTRYLEN		1024	/* Max line length */
 
+void release_lastbind(struct host *hp);
 
 
 
