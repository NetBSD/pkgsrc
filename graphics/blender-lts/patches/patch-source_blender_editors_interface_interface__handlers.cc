$NetBSD: patch-source_blender_editors_interface_interface__handlers.cc,v 1.1 2024/07/25 06:00:39 ryoon Exp $

--- source/blender/editors/interface/interface_handlers.cc.orig	2024-07-02 09:48:42.973784856 +0000
+++ source/blender/editors/interface/interface_handlers.cc
@@ -4107,10 +4107,10 @@ static void ui_numedit_begin(uiBut *but,
         /* Center around the value, keeping in the real soft min/max range. */
         softmin = data->origvalue - (softrange_max / 2);
         softmax = data->origvalue + (softrange_max / 2);
-        if (!isfinite(softmin)) {
+        if (!std::isfinite(softmin)) {
           softmin = (data->origvalue > 0.0f ? FLT_MAX : -FLT_MAX);
         }
-        if (!isfinite(softmax)) {
+        if (!std::isfinite(softmax)) {
           softmax = (data->origvalue > 0.0f ? FLT_MAX : -FLT_MAX);
         }
 
@@ -5501,7 +5501,7 @@ static int ui_do_but_NUM(
           double precision = (roundf(log10f(data->value) + UI_PROP_SCALE_LOG_SNAP_OFFSET) - 1.0f) +
                              log10f(number_but->step_size);
           /* Non-finite when `data->value` is zero. */
-          if (UNLIKELY(!isfinite(precision))) {
+          if (UNLIKELY(!std::isfinite(precision))) {
             precision = -FLT_MAX; /* Ignore this value. */
           }
           value_step = powf(10.0f, max_ff(precision, -number_but->precision));
