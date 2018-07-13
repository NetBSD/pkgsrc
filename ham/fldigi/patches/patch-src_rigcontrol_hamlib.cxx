$NetBSD: patch-src_rigcontrol_hamlib.cxx,v 1.1 2018/07/13 04:14:48 dbj Exp $

The C++ std::sort requires the comparator return false when items are equal

--- src/rigcontrol/hamlib.cxx.orig	2017-11-08 12:41:13.000000000 +0000
+++ src/rigcontrol/hamlib.cxx
@@ -582,10 +582,10 @@ static bool rig_cmp(const struct rig_cap
 	if (ret < 0) return true;
 	ret = strcasecmp(rig1->model_name, rig2->model_name);
 	if (ret > 0) return false;
-	if (ret <= 0) return true;
-	if (rig1->rig_model > rig2->rig_model)
-		return false;
-	return true;
+	if (ret < 0) return true;
+	if (rig1->rig_model < rig2->rig_model)
+		return true;
+	return false;
 }
 
 void hamlib_get_rigs(void)
