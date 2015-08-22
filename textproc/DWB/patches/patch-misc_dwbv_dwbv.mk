$NetBSD: patch-misc_dwbv_dwbv.mk,v 1.1 2015/08/22 20:51:31 leot Exp $

Mark as executeable

--- misc/dwbv/dwbv.mk.orig	2015-05-19 15:28:04.000000000 +0200
+++ misc/dwbv/dwbv.mk	2015-05-19 15:29:00.000000000 +0200
@@ -28,7 +28,8 @@
 	rm -f dwbv
 
 dwbv ::
-	@echo "echo DWB $(VERSION)" >dwbv
+	@echo "#!/bin/sh" >dwbv
+	@echo "echo DWB $(VERSION)" >>dwbv
 
 changes :
 	@trap "" 1 2 3 15; \
