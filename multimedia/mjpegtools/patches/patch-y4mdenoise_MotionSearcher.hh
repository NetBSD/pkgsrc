$NetBSD: patch-y4mdenoise_MotionSearcher.hh,v 1.1 2012/07/07 15:49:01 adam Exp $

Fix C++ error

--- y4mdenoise/MotionSearcher.hh.orig	2012-07-07 13:03:45.000000000 +0000
+++ y4mdenoise/MotionSearcher.hh
@@ -2196,7 +2196,7 @@ MotionSearcher<PIXEL_NUM,DIM,PIXEL_TOL,P
 	{
 		// This region is too small to be bothered with.
 		// Just get rid of it.
-		DeleteRegion (a_pRegion);
+		this->DeleteRegion (a_pRegion);
 	}
 	else
 	{
