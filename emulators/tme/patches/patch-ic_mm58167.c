$NetBSD: patch-ic_mm58167.c,v 1.1 2020/03/05 14:55:16 thorpej Exp $

Don't abort the emulator if we get a read for an unexpected register (which
seems to happen with NetBSD 9 on sun2); just return 0 instead.

--- ic/mm58167.c.orig	2020-03-05 14:20:42.000000000 +0000
+++ ic/mm58167.c	2020-03-05 14:21:25.000000000 +0000
@@ -219,7 +219,8 @@ _tme_mm58167_bus_cycle(void *_mm58167, s
       mm58167->tme_mm58167_status = 0;
       break;
     default:
-      abort();
+      value = 0;
+      break;
     }
 
     /* if needed, convert this value to BCD: */
