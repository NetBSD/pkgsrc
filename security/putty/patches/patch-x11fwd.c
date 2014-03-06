$NetBSD: patch-x11fwd.c,v 1.1 2014/03/06 15:45:09 joerg Exp $

--- x11fwd.c.orig	2014-03-02 19:24:55.000000000 +0000
+++ x11fwd.c
@@ -2,6 +2,7 @@
  * Platform-independent bits of X11 forwarding.
  */
 
+#include <inttypes.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
@@ -312,7 +313,7 @@ static char *x11_verify(unsigned long pe
 	    if (data[i] != 0)	       /* zero padding wrong */
 		return "XDM-AUTHORIZATION-1 data failed check";
 	tim = time(NULL);
-	if (abs(t - tim) > XDM_MAXSKEW)
+	if (imaxabs((intmax_t)t - tim) > XDM_MAXSKEW)
 	    return "XDM-AUTHORIZATION-1 time stamp was too far out";
 	seen = snew(struct XDMSeen);
 	seen->time = t;
