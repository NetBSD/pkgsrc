$NetBSD: patch-libefont_findmet.cc,v 1.1 2018/12/27 15:16:53 joerg Exp $

--- libefont/findmet.cc.orig	2018-12-25 23:18:27.648547856 +0000
+++ libefont/findmet.cc
@@ -188,7 +188,8 @@ Metrics *
 InstanceMetricsFinder::find_metrics_instance(PermString name,
 					     MetricsFinder *finder, ErrorHandler *errh)
 {
-    char *underscore = strchr(name, '_');
+    char *underscore2;
+    const char *underscore = strchr(name, '_');
     PermString amfm_name =
 	PermString(name.cc(), underscore - name.cc());
   
@@ -214,7 +215,8 @@ InstanceMetricsFinder::find_metrics_inst
     Vector<double> design = mmspace->default_design_vector();
     int i = 0;
     while (underscore[0] == '_' && underscore[1]) {
-	double x = strtod(underscore + 1, &underscore);
+	double x = strtod(underscore + 1, &underscore2);
+	underscore = underscore2;
 	mmspace->set_design(design, i, x, errh);
 	i++;
     }
