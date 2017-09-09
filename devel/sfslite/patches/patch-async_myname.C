$NetBSD: patch-async_myname.C,v 1.1 2017/09/09 19:45:46 dholland Exp $

Clean up %m abuse.

--- async/myname.C~	2009-02-12 13:20:42.000000000 +0000
+++ async/myname.C
@@ -21,6 +21,7 @@
  *
  */
 
+#include <cstring>
 #include "dns.h"
 
 str
@@ -42,7 +43,7 @@ myname ()
   char namebuf[MAXHOSTNAMELEN+1];
   namebuf[MAXHOSTNAMELEN] = '\0';
   if (gethostname (namebuf, MAXHOSTNAMELEN) < 0)
-    panic ("gethostname: %m\n");
+    panic ("gethostname: %s\n", strerror(errno));
 
   if (strchr (namebuf, '.'))
     return namebuf;
