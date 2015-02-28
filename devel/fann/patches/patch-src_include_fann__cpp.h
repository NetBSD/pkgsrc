$NetBSD: patch-src_include_fann__cpp.h,v 1.1 2015/02/28 23:43:01 joerg Exp $

--- src/include/fann_cpp.h.orig	2015-02-28 23:14:12.000000000 +0000
+++ src/include/fann_cpp.h
@@ -954,10 +954,16 @@ public:
         */ 
         bool create_standard(unsigned int num_layers, ...)
         {
+            if (num_layers == 0)
+              return create_standard_array(num_layers, NULL);
             va_list layers;
             va_start(layers, num_layers);
-            bool status = create_standard_array(num_layers,
-                reinterpret_cast<const unsigned int *>(layers));
+            // XXX not exception safe
+            unsigned int *layers_array = new unsigned int[num_layers];
+            for (unsigned i = 0; i < num_layers; ++i)
+              layers_array[i] = va_arg(layers, unsigned int);
+            bool status = create_standard_array(num_layers, layers_array);
+            delete[] layers_array;
             va_end(layers);
             return status;
         }
@@ -1004,10 +1010,16 @@ public:
         */
         bool create_sparse(float connection_rate, unsigned int num_layers, ...)
         {
+            if (num_layers == 0)
+              return create_sparse_array(connection_rate, num_layers, NULL);
             va_list layers;
             va_start(layers, num_layers);
-            bool status = create_sparse_array(connection_rate, num_layers,
-                reinterpret_cast<const unsigned int *>(layers));
+            // XXX not exception safe
+            unsigned int *layers_array = new unsigned int[num_layers];
+            for (unsigned i = 0; i < num_layers; ++i)
+              layers_array[i] = va_arg(layers, unsigned int);
+            bool status = create_sparse_array(connection_rate, num_layers, layers_array);
+            delete[] layers_array;
             va_end(layers);
             return status;
         }
@@ -1051,10 +1063,16 @@ public:
         */ 
         bool create_shortcut(unsigned int num_layers, ...)
         {
+            if (num_layers == 0)
+              return create_shortcut_array(num_layers, NULL);
             va_list layers;
             va_start(layers, num_layers);
-            bool status = create_shortcut_array(num_layers,
-                reinterpret_cast<const unsigned int *>(layers));
+            // XXX not exception safe
+            unsigned int *layers_array = new unsigned int[num_layers];
+            for (unsigned i = 0; i < num_layers; ++i)
+              layers_array[i] = va_arg(layers, unsigned int);
+            bool status = create_shortcut_array(num_layers, layers_array);
+            delete[] layers_array;
             va_end(layers);
             return status;
         }
