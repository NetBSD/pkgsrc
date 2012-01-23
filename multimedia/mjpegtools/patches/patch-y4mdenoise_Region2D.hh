$NetBSD: patch-y4mdenoise_Region2D.hh,v 1.1 2012/01/23 08:09:36 joerg Exp $

--- y4mdenoise/Region2D.hh.orig	2012-01-23 01:52:49.000000000 +0000
+++ y4mdenoise/Region2D.hh
@@ -381,7 +381,7 @@ Region2D<INDEX,SIZE>::Assign (Status_t &
 	assert (a_reStatus == g_kNoError);
 
 	// Assign the other region's extents to ourselves.
-	Region2D<INDEX,SIZE>::Clear();
+	this->Clear();
 	for (typename REGION::ConstIterator itHere = a_rOther.Begin();
 		 itHere != a_rOther.End();
 		 ++itHere)
@@ -754,7 +754,7 @@ Region2D<INDEX,SIZE>::FloodFill (Status_
 			a_rControl.m_oToDo.Assign (a_reStatus, *this);
 			if (a_reStatus != g_kNoError)
 				return;
-			Region2D<INDEX,SIZE>::Clear();
+			this->Clear();
 		}
 	}
 	else
@@ -889,7 +889,7 @@ Region2D<INDEX,SIZE>::MakeBorder (Status
 	assert (a_reStatus == g_kNoError);
 
 	// Start with an empty region.
-	Region2D<INDEX,SIZE>::Clear();
+	this->Clear();
 
 	// For every extent in the other region, add every surrounding
 	// extent.  That creates a region that looks like the other region,
