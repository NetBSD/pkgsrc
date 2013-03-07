$NetBSD: patch-grouter_grouteDens.c,v 1.2 2013/03/07 22:05:12 joerg Exp $

--- grouter/grouteDens.c.orig	2013-03-02 22:20:54.000000000 +0000
+++ grouter/grouteDens.c
@@ -78,7 +78,7 @@ glDensAdjust(dens, srcPin, dstPin, netid
     ASSERT(srcPin->gcr_ch == dstPin->gcr_ch, "glDensAdjust");
 
     if (DebugIsSet(glDebugID, glDebGreedy))
-	return;
+	return FALSE;
 
     /*
      * Find the first and last column where this net (netId)
