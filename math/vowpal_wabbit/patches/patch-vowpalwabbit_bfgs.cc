$NetBSD: patch-vowpalwabbit_bfgs.cc,v 1.1 2016/10/01 13:04:16 joerg Exp $

--- vowpalwabbit/bfgs.cc.orig	2016-09-30 09:20:08.000000000 +0000
+++ vowpalwabbit/bfgs.cc
@@ -15,7 +15,7 @@ Implementation by Miro Dudik.
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include "accumulate.h"
 #include "gd.h"
 #include "vw_exception.h"
@@ -62,10 +62,10 @@ struct bfgs
   double wolfe1_bound;
 
   size_t final_pass;
-  struct timeb t_start, t_end;
+  struct timeval t_start, t_end;
   double net_comm_time;
 
-  struct timeb t_start_global, t_end_global;
+  struct timeval t_start_global, t_end_global;
   double net_time;
 
   v_array<float> predictions;
@@ -553,8 +553,8 @@ int process_pass(vw& all, bfgs& b)
     else
     { b.step_size = 0.5;
       float d_mag = direction_magnitude(all);
-      ftime(&b.t_end_global);
-      b.net_time = (int) (1000.0 * (b.t_end_global.time - b.t_start_global.time) + (b.t_end_global.millitm - b.t_start_global.millitm));
+      gettimeofday(&b.t_end_global, NULL);
+      b.net_time = (int) (1000.0 * (b.t_end_global.tv_sec - b.t_start_global.tv_sec) + 0.001 * (b.t_end_global.tv_usec - b.t_start_global.tv_usec));
       if (!all.quiet)
         fprintf(stderr, "%-10s\t%-10.5f\t%-10.5f\n", "", d_mag, b.step_size);
       b.predictions.erase();
@@ -602,8 +602,8 @@ int process_pass(vw& all, bfgs& b)
       /********************************************************************/
       else if (b.backstep_on && (wolfe1<b.wolfe1_bound || b.loss_sum > b.previous_loss_sum))
       { // curvature violated, or we stepped too far last time: step back
-        ftime(&b.t_end_global);
-        b.net_time = (int) (1000.0 * (b.t_end_global.time - b.t_start_global.time) + (b.t_end_global.millitm - b.t_start_global.millitm));
+        gettimeofday(&b.t_end_global, NULL);
+        b.net_time = (int) (1000.0 * (b.t_end_global.tv_sec - b.t_start_global.tv_sec) + 0.001 * (b.t_end_global.tv_usec - b.t_start_global.tv_usec));
         float ratio = (b.step_size==0.f) ? 0.f : (float)new_step/(float)b.step_size;
         if (!all.quiet)
           fprintf(stderr, "%-10s\t%-10s\t(revise x %.1f)\t%-10.5f\n",
@@ -647,8 +647,8 @@ int process_pass(vw& all, bfgs& b)
         }
         else
         { float d_mag = direction_magnitude(all);
-          ftime(&b.t_end_global);
-          b.net_time = (int) (1000.0 * (b.t_end_global.time - b.t_start_global.time) + (b.t_end_global.millitm - b.t_start_global.millitm));
+          gettimeofday(&b.t_end_global, NULL);
+          b.net_time = (int) (1000.0 * (b.t_end_global.tv_sec - b.t_start_global.tv_sec) + 0.001 * (b.t_end_global.tv_usec - b.t_start_global.tv_usec));
           if (!all.quiet)
             fprintf(stderr, "%-10s\t%-10.5f\t%-10.5f\n", "", d_mag, b.step_size);
           b.predictions.erase();
@@ -685,8 +685,8 @@ int process_pass(vw& all, bfgs& b)
 
       b.predictions.erase();
       update_weight(all, b.step_size);
-      ftime(&b.t_end_global);
-      b.net_time = (int) (1000.0 * (b.t_end_global.time - b.t_start_global.time) + (b.t_end_global.millitm - b.t_start_global.millitm));
+      gettimeofday(&b.t_end_global, NULL);
+      b.net_time = (int) (1000.0 * (b.t_end_global.tv_sec - b.t_start_global.tv_sec) + 0.001 * (b.t_end_global.tv_usec - b.t_start_global.tv_usec));
       if (!all.quiet)
         fprintf(stderr, "%-10.5f\t%-10.5f\t%-10.5f\n", b.curvature / b.importance_weight_sum, d_mag, b.step_size);
       b.gradient_pass = true;
@@ -700,8 +700,8 @@ int process_pass(vw& all, bfgs& b)
       accumulate(all, all.reg, W_COND); //Accumulate preconditioner
     //preconditioner_to_regularizer(all, b, all.l2_lambda);
   }
-  ftime(&b.t_end_global);
-  b.net_time = (int) (1000.0 * (b.t_end_global.time - b.t_start_global.time) + (b.t_end_global.millitm - b.t_start_global.millitm));
+  gettimeofday(&b.t_end_global, NULL);
+  b.net_time = (int) (1000.0 * (b.t_end_global.tv_sec - b.t_start_global.tv_sec) + 0.001 * (b.t_end_global.tv_usec - b.t_start_global.tv_usec));
 
   if (all.save_per_pass)
     save_predictor(all, all.final_regressor_name, b.current_pass);
@@ -883,7 +883,7 @@ void save_load(bfgs& b, io_buf& model_fi
     }
 
     b.net_time = 0.0;
-    ftime(&b.t_start_global);
+    gettimeofday(&b.t_start_global, NULL);
 
     if (!all->quiet)
     { const char * header_fmt = "%2s %-10s\t%-10s\t%-10s\t %-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n";
