$NetBSD: patch-src_rigcontrol_hamlib.cxx,v 1.3 2025/01/14 01:30:02 gdt Exp $

Accomodate hamlib 4.6 API break.

Not yet filed upstream because we are behind.

--- src/rigcontrol/hamlib.cxx.orig	2025-01-14 01:26:36.015676963 +0000
+++ src/rigcontrol/hamlib.cxx
@@ -567,7 +567,7 @@ static void *hamlib_loop(void *args)
 	return NULL;
 }
 
-static int add_to_list(const struct rig_caps* rc, void*)
+static int add_to_list(struct rig_caps* rc, void*)
 {
 	hamlib_rigs.push_back(rc);
 	return 1;
