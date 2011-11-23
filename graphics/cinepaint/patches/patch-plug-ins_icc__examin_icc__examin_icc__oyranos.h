$NetBSD: patch-plug-ins_icc__examin_icc__examin_icc__oyranos.h,v 1.1 2011/11/23 23:30:30 joerg Exp $

--- plug-ins/icc_examin/icc_examin/icc_oyranos.h.orig	2011-11-23 17:00:10.000000000 +0000
+++ plug-ins/icc_examin/icc_examin/icc_oyranos.h
@@ -34,6 +34,7 @@
 #include "icc_speicher.h"
 #include "icc_vrml_parser.h"
 
+#include <cstring>
 #include <string>
 #include <list>
 #include <map>
@@ -146,8 +147,8 @@ class Oyranos
                                   int         byte,
                                   int         kanaele,
                                   const char* ausgangs_profil__geraet,
-                                  int         byte,
-                                  int         kanaele,
+                                  int         ausgangs_byte,
+                                  int         ausgangs_kanaele,
                                   int         farb_intent,
                                   const char* cmm, // 4 bytes 'lcms' 'APPL'
                                   int         cmm_optionen); // BPC, precission
@@ -156,8 +157,8 @@ class Oyranos
                                   int         byte,
                                   int         kanaele,
                                   const char* ausgangs_profil__geraet,
-                                  int         byte,
-                                  int         kanaele,
+                                  int         ausgangs_byte,
+                                  int         ausgangs_kanaele,
                                   int         farb_intent,
                                   const char* cmm, // 4 bytes 'lcms' 'APPL'
                                   int         cmm_optionen,
@@ -167,8 +168,8 @@ class Oyranos
                                   int         byte,
                                   int         kanaele,
                                   const char* ausgangs_profil__geraet,
-                                  int         byte,
-                                  int         kanaele,
+                                  int         ausgangs_byte,
+                                  int         ausgangs_kanaele,
                                   int         farb_intent,
                                   const char* cmm, // 4 bytes 'lcms' 'APPL'
                                   int         cmm_optionen,
@@ -185,8 +186,8 @@ class Oyranos
                                   int         byte,
                                   int         kanaele,
                                   const char* ausgangs_profil__geraet,
-                                  int         byte,
-                                  int         kanaele,
+                                  int         ausgangs_byte,
+                                  int         ausgangs_kanaele,
                                   int         farb_intent,
                                   int         cmm_optionen,
                                   const char* simulations_profil,
