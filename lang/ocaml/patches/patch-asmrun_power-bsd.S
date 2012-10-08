$NetBSD: patch-asmrun_power-bsd.S,v 1.1 2012/10/08 15:05:32 jaapb Exp $

Add profiling to power architecture
--- asmrun/power-bsd.S.orig	2012-09-11 13:01:14.000000000 +0000
+++ asmrun/power-bsd.S
@@ -15,2 +15,31 @@
 
+#if defined(PROFILING)
+#define PROFILE_CAML \
+        stwu 1, -32(1) \
+        mflr 0 \
+        stw 0, 4(1) \
+        stw 2, 8(1) \
+        stw 3, 12(1) \
+        stw 4, 16(1) \
+        stw 5, 20(1) \
+        stw 6, 24(1) \
+        stw 7, 28(1) \
+        bl _mcount \                
+        lwz 2, 8(1) \               
+        lwz 3, 12(1) \              
+        lwz 4, 16(1) \              
+        lwz 5, 20(1) \              
+        lwz 6, 24(1) \              
+        lwz 7, 28(1) \
+        addic 1, 1, 32
+
+#define PROFILE_C \
+        mflr 0 \
+        stw 0, 4(1) \               
+        bl _mcount                  
+#else                               
+#define PROFILE_CAML                
+#define PROFILE_C                   
+#endif                              
+
 #define Addrglobal(reg,glob) \
@@ -35,2 +64,3 @@ caml_system__code_begin:
 caml_call_gc:
+        PROFILE_CAML
     /* Set up stack frame */
@@ -187,2 +217,3 @@ caml_call_gc:
 caml_c_call:
+        PROFILE_CAML
     /* Save return address */
@@ -215,2 +246,3 @@ caml_c_call:
 caml_raise_exception:
+        P ROFILE_C
     /* Reload OCaml global registers */
@@ -235,2 +267,3 @@ caml_raise_exception:
 caml_start_program:
+        PROFILE_C
         Addrglobal(12, caml_program)
@@ -385,2 +418,3 @@ caml_start_program:
 caml_callback_exn:
+        PROFILE_C
     /* Initial shuffling of arguments */
@@ -395,2 +429,3 @@ caml_callback_exn:
 caml_callback2_exn:
+        PROFILE_C
         mr      0, 3            /* Closure */
@@ -405,2 +440,3 @@ caml_callback2_exn:
 caml_callback3_exn:
+        PROFILE_C
         mr      0, 3            /* Closure */
