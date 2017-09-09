$NetBSD: patch-async_ifchg.C,v 1.1 2017/09/09 19:45:46 dholland Exp $

Clean up %m abuse.

--- async/ifchg.C~	2009-02-12 13:20:42.000000000 +0000
+++ async/ifchg.C
@@ -21,6 +21,7 @@
  *
  */
 
+#include <cstring>
 #include "async.h"
 #include "dns.h"
 #include "list.h"
@@ -74,7 +75,7 @@ ifchgcb (cbv cb)
 {
   if (!lazy) {
     if (!myipaddrs (&ifchg_addrs))
-      fatal ("myipaddrs: %m\n");
+      fatal ("myipaddrs: %s\n", strerror(errno));
     lazy = lazycb (60, wrap (ifchgcb_test));
   }
   ifchgcb_t *chg = New ifchgcb_t (cb);
