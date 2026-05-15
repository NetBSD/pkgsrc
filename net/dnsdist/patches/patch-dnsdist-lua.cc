$NetBSD: patch-dnsdist-lua.cc,v 1.1 2026/05/15 09:15:48 adam Exp $

Fix build with boost 1.91.0.

--- dnsdist-lua.cc.orig	2026-04-22 17:37:43.000000000 +0000
+++ dnsdist-lua.cc
@@ -3084,7 +3084,7 @@ static void setupLuaConfig(LuaContext& l
         customName = std::optional(*optCustomName);
       }
       if (!customName) {
-        boost::optional<declare_metric_opts_t> vars = {boost::get<declare_metric_opts_t>(opts.get())};
+        boost::optional<declare_metric_opts_t> vars{boost::get<declare_metric_opts_t>(opts.get())};
         getOptionalValue<std::string>(vars, "customName", customName);
         getOptionalValue<bool>(vars, "withLabels", withLabels);
         checkAllParametersConsumed("declareMetric", vars);
@@ -3107,7 +3107,7 @@ static void setupLuaConfig(LuaContext& l
       step = *custom_step;
     }
     else {
-      boost::optional<update_metric_opts_t> vars = {boost::get<update_metric_opts_t>(incOpts)};
+      boost::optional<update_metric_opts_t> vars{boost::get<update_metric_opts_t>(incOpts)};
       getOptionalValue<uint64_t>(vars, "step", step);
       getOptionalValue<LuaAssociativeTable<std::string>>(vars, "labels", labels);
       checkAllParametersConsumed("incMetric", vars);
@@ -3129,7 +3129,7 @@ static void setupLuaConfig(LuaContext& l
       step = *custom_step;
     }
     else {
-      boost::optional<update_metric_opts_t> vars = {boost::get<update_metric_opts_t>(decOpts)};
+      boost::optional<update_metric_opts_t> vars{boost::get<update_metric_opts_t>(decOpts)};
       getOptionalValue<uint64_t>(vars, "step", step);
       getOptionalValue<LuaAssociativeTable<std::string>>(vars, "labels", labels);
       checkAllParametersConsumed("decMetric", vars);
