$NetBSD: patch-libraw_internal_wf_filtering.cpp,v 1.1 2013/04/03 10:52:12 markd Exp $

--- libraw/internal/wf_filtering.cpp.orig	2013-03-01 07:01:45.000000000 +0000
+++ libraw/internal/wf_filtering.cpp
@@ -682,7 +682,8 @@ int LibRaw::wf_remove_banding()
 	}
 
 	free(dummy_line);
-	
+	return WF_DEBANDING_OK;
+ 	
 }
 
 double LibRaw::wf_filter_energy(int r1_greenmode, int r1, int r2_greenmode, int r2)
