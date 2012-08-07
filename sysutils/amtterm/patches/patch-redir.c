--- redir.c.orig	2011-05-26 18:19:45.000000000 +0900
+++ redir.c	2012-08-07 13:08:49.000000000 +0900
@@ -281,8 +281,11 @@
 
 	switch (count) {
 	case -1:
-	    snprintf(r->err, sizeof(r->err), "read(socket): %s", strerror(errno));
-	    return -1;
+	    if (errno != EAGAIN) {
+	      snprintf(r->err, sizeof(r->err), "read(socket): %s", strerror(errno));
+	      return -1;
+	    }
+	    break;
 	case 0:
 	    snprintf(r->err, sizeof(r->err), "EOF from socket");
 	    return -1;
