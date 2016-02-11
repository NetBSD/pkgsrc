$NetBSD: patch-slpd_slpd__knownda.c,v 1.1 2016/02/11 15:12:06 he Exp $

Add fix for CVE-2015-5177, lifted from
https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=795429

--- slpd/slpd_knownda.c.orig	2005-02-08 05:34:31.000000000 +0000
+++ slpd/slpd_knownda.c
@@ -823,15 +823,15 @@ int SLPDKnownDAAdd(SLPMessage msg, SLPBu
              */
             SLPDLogDAAdvertisement("Removed",entry);
         }
+        /* If we are here, we need to cleanup the message descriptor and the  */
+        /* message buffer because they were not added to the database and not */
+        /* cleaning them up would result in a memory leak                     */
+        /* We also need to make sure the Database handle is closed.           */
+        SLPMessageFree(msg);
+        SLPBufferFree(buf);
     }
 
     CLEANUP:
-    /* If we are here, we need to cleanup the message descriptor and the  */
-    /* message buffer because they were not added to the database and not */
-    /* cleaning them up would result in a memory leak                     */
-    /* We also need to make sure the Database handle is closed.           */
-    SLPMessageFree(msg);
-    SLPBufferFree(buf);
     if (dh) SLPDatabaseClose(dh);
 
     return result;
