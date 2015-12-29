$NetBSD: patch-libf95.a-0.93_intrinsics_matmul10.c,v 1.2 2015/12/29 23:34:46 dholland Exp $

Fix assembler instructions.

--- libf95.a-0.93/intrinsics/matmul10.c.orig	2013-03-01 11:13:29.000000000 +0000
+++ libf95.a-0.93/intrinsics/matmul10.c
@@ -899,7 +899,7 @@ static char matrix_mismatch[] = "Matrix 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "movsbl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (q), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (q), "m" (temp) : EAX
 
 #include "matmul10.c"
 
@@ -913,7 +913,7 @@ static char matrix_mismatch[] = "Matrix 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "movswl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (q), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (q), "m" (temp) : EAX
 
 #include "matmul10.c"
 
@@ -925,7 +925,7 @@ static char matrix_mismatch[] = "Matrix 
                  "fldt ( %" EAX ")\n" : : "m" (p) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
-                 "fild ( %" EAX ")\n" : : "m" (q) : EAX
+                 "filds ( %" EAX ")\n" : : "m" (q) : EAX
 
 #include "matmul10.c"
 
@@ -972,7 +972,7 @@ static char matrix_mismatch[] = "Matrix 
 #define LOAD_A   "mov %0, %" EAX "\n" \
                  "movsbl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (p), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (p), "m" (temp) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" : : "m" (q) : EAX
@@ -987,7 +987,7 @@ static char matrix_mismatch[] = "Matrix 
 #define LOAD_A   "mov %0, %" EAX "\n" \
                  "movswl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (p), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (p), "m" (temp) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" : : "m" (q) : EAX
@@ -999,7 +999,7 @@ static char matrix_mismatch[] = "Matrix 
 #define SUBROUTINE22     prefix(matmul22_i4r10)
 
 #define LOAD_A   "mov %0, %" EAX "\n" \
-                 "fild ( %" EAX ")\n" : : "m" (p), "m" (temp) : EAX
+                 "filds ( %" EAX ")\n" : : "m" (p), "m" (temp) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" : : "m" (q) : EAX
@@ -1113,7 +1113,7 @@ static char matrix_mismatch[] = "Matrix 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "movsbl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (q), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (q), "m" (temp) : EAX
 
 #define LOAD_RESULT "mov %0, %" EAX "\n" \
                     "fldt (%" EAX ")\n" \
@@ -1140,7 +1140,7 @@ static char matrix_mismatch[] = "Matrix 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "movswl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (q), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (q), "m" (temp) : EAX
 
 #define LOAD_RESULT "mov %0, %" EAX "\n" \
                     "fldt (%" EAX ")\n" \
@@ -1166,7 +1166,7 @@ static char matrix_mismatch[] = "Matrix 
                   : : "m" (p) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
-                 "fild (%" EAX ")\n" : : "m" (q) : EAX
+                 "filds (%" EAX ")\n" : : "m" (q) : EAX
 
 #define LOAD_RESULT "mov %0, %" EAX "\n" \
                     "fldt (%" EAX ")\n" \
@@ -1340,7 +1340,7 @@ static char matrix_mismatch[] = "Matrix 
 #define LOAD_A   "mov %0, %" EAX "\n" \
                  "movsbl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (p), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (p), "m" (temp) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" \
@@ -1368,7 +1368,7 @@ static char matrix_mismatch[] = "Matrix 
 #define LOAD_A   "mov %0, %" EAX "\n" \
                  "movswl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (p), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (p), "m" (temp) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" \
@@ -1394,7 +1394,7 @@ static char matrix_mismatch[] = "Matrix 
 #define SUBROUTINE22    prefix(matmul22_i4z10)
 
 #define LOAD_A   "mov %0, %" EAX "\n" \
-                 "fild (%" EAX ")\n" : : "m" (p) : EAX
+                 "filds (%" EAX ")\n" : : "m" (p) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" \
