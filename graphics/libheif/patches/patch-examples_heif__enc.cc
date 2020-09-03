$NetBSD: patch-examples_heif__enc.cc,v 1.1 2020/09/03 19:07:19 otis Exp $

Excplicitly cast types to make ISO C++ happy

--- examples/heif_enc.cc.orig	2020-08-14 15:28:08.000000000 +0000
+++ examples/heif_enc.cc
@@ -71,21 +71,21 @@ int nclx_transfer_characteristic = 2;
 int nclx_full_range = true;
 
 static struct option long_options[] = {
-    {"help",                    no_argument,       0,                             'h'},
-    {"quality",                 required_argument, 0,                             'q'},
-    {"output",                  required_argument, 0,                             'o'},
-    {"lossless",                no_argument,       0,                             'L'},
-    {"thumb",                   required_argument, 0,                             't'},
-    {"verbose",                 no_argument,       0,                             'v'},
-    {"params",                  no_argument,       0,                             'P'},
-    {"no-alpha",                no_argument,       &master_alpha,                 0},
-    {"no-thumb-alpha",          no_argument,       &thumb_alpha,                  0},
-    {"bit-depth",               required_argument, 0,                             'b'},
-    {"avif",                    no_argument,       0,                             'A'},
-    {"matrix_coefficients",     required_argument, &nclx_matrix_coefficients,     0},
-    {"colour_primaries",        required_argument, &nclx_colour_primaries,        0},
-    {"transfer_characteristic", required_argument, &nclx_transfer_characteristic, 0},
-    {"full_range_flag",         required_argument, &nclx_full_range,              0},
+    {(char * const)"help",                    no_argument,       0,                             'h'},
+    {(char * const)"quality",                 required_argument, 0,                             'q'},
+    {(char * const)"output",                  required_argument, 0,                             'o'},
+    {(char * const)"lossless",                no_argument,       0,                             'L'},
+    {(char * const)"thumb",                   required_argument, 0,                             't'},
+    {(char * const)"verbose",                 no_argument,       0,                             'v'},
+    {(char * const)"params",                  no_argument,       0,                             'P'},
+    {(char * const)"no-alpha",                no_argument,       &master_alpha,                 0},
+    {(char * const)"no-thumb-alpha",          no_argument,       &thumb_alpha,                  0},
+    {(char * const)"bit-depth",               required_argument, 0,                             'b'},
+    {(char * const)"avif",                    no_argument,       0,                             'A'},
+    {(char * const)"matrix_coefficients",     required_argument, &nclx_matrix_coefficients,     0},
+    {(char * const)"colour_primaries",        required_argument, &nclx_colour_primaries,        0},
+    {(char * const)"transfer_characteristic", required_argument, &nclx_transfer_characteristic, 0},
+    {(char * const)"full_range_flag",         required_argument, &nclx_full_range,              0},
     {0, 0,                                         0,                             0}
 };
 
