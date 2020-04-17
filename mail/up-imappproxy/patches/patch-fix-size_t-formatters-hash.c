$NetBSD: patch-fix-size_t-formatters-hash.c,v 1.1 2020/04/17 11:28:02 tm Exp $

Fix size_t formatters

Richard Laager <rlaager@wiktel.com>
https://sourceforge.net/p/squirrelmail/mailman/message/35526927/

--- src/hash.c.orig
+++ src/hash.c
@@ -69,7 +69,7 @@
 
   if ( Size > sizeof Hash_Buffer )
   {
-    syslog(LOG_ERR, "Hash(): Maximum of %d for '%s' exceeds architectural limit of %d", Size, Input_Key, sizeof Hash_Buffer );
+    syslog(LOG_ERR, "Hash(): Maximum of %d for '%s' exceeds architectural limit of %zd", Size, Input_Key, sizeof Hash_Buffer );
     exit(1);
   }
 
