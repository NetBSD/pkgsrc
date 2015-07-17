$NetBSD: patch-src_extra_gd_gdft.c,v 1.1 2015/07/17 12:33:47 sevan Exp $

CVE-2007-0455 - Buffer overflow in the gdImageStringFTEx

--- src/extra/gd/gdft.c.orig	2005-07-27 20:35:05.000000000 +0000
+++ src/extra/gd/gdft.c
@@ -809,7 +809,7 @@ gdImageStringFT (gdImage * im, int *brec
 	    {
 	      ch = c & 0xFF;	/* don't extend sign */
 	    }
-	  next++;
+	  if (*next) next++;
 	}
       else
 	{
