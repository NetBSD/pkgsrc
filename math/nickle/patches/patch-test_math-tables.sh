$NetBSD: patch-test_math-tables.sh,v 1.1 2025/04/30 11:43:13 wiz Exp $

From fc36b91c5d783d718f89debea1a1d4933ef844e2 Mon Sep 17 00:00:00 2001
From: Keith Packard <keithp@keithp.com>
Date: Tue, 29 Apr 2025 22:34:06 -0700
Subject: [PATCH] test: Use fmt -w 500 instead of fmt --width=500

--width appears to be a GNU extension.

Signed-off-by: Keith Packard <keithp@keithp.com>

--- test/math-tables.sh.orig	2025-04-28 22:56:10.000000000 +0000
+++ test/math-tables.sh
@@ -61,10 +61,10 @@ echo "sin_cos_t[] sin_cos_table = {"
 
 a="-800"
 while [ "$a" -le "800" -a $make_sin = "y" ]; do
-    sin=`echo "s($a / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
-    cos=`echo "c($a / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
-    psin=`echo "s(p * $a / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
-    pcos=`echo "c(p * $a / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
+    sin=`echo "s($a / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
+    cos=`echo "c($a / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
+    psin=`echo "s(p * $a / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
+    pcos=`echo "c(p * $a / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
     echo "    { .angle = $a / 100.0,"
     echo "      .sin = $sin,"
     echo "      .cos = $cos },"
@@ -83,8 +83,8 @@ echo "asin_acos_t[] asin_acos_table = {"
 
 r="-200"
 while [ "$r" -le 200 -a $make_asin = "y" ]; do
-    asin=`echo "b($r / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
-    acos=`echo "d($r / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
+    asin=`echo "b($r / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
+    acos=`echo "d($r / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
     echo "    { .ratio = $r / 100,"
     echo "      .asin = $asin,"
     echo "      .acos = $acos },"
@@ -100,8 +100,8 @@ echo "tan_t[] tan_table = {"
 
 a="-800"
 while [ "$a" -le 800 -a $make_tan = "y" ]; do
-    tan=`echo "t($a / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
-    ptan=`echo "t(p * $a / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
+    tan=`echo "t($a / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
+    ptan=`echo "t(p * $a / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
     echo "    { .angle = $a / 100.0,"
     echo "      .tan = $tan },"
     echo "    { .angle = π * $a / 100.0,"
@@ -117,7 +117,7 @@ echo "atan_t[] atan_table = {"
 
 r="-1000"
 while [ "$r" -le 1000 -a $make_atan = "y" ]; do
-    atan=`echo "a($r / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
+    atan=`echo "a($r / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
     echo "    { .ratio = $r / 100,"
     echo "      .atan = $atan },"
     r=`expr "$r" + "$inc"`
@@ -134,7 +134,7 @@ while [ "$y" -le 30 -a "$make_atan" = "y
       x="-30"
       while [ "$x" -le 30 ]; do
 	  x=`expr "$x" + "$ainc"`
-	  atan2=`echo "u($y / 100, $x / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
+	  atan2=`echo "u($y / 100, $x / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
 	  echo "    { .y = $y / 100.0, .x = $x / 100.0,"
 	  echo "      .atan2 = $atan2 },"
       done
@@ -150,7 +150,7 @@ echo "log_t[] log_table = {"
 r="0"
 while [ "$r" -le 66 -a "$make_log" = "y" ]; do
     in=`echo "2 ^ $r" | bc`
-    log=`echo "l($in / 1000000)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
+    log=`echo "l($in / 1000000)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
     echo "    { .in = $in / 1000000.0,"
     echo "      .log = $log },"
     r=`expr "$r" + "$ainc"`
@@ -164,7 +164,7 @@ echo "exp_t[] exp_table = {"
 
 r="-1000"
 while [ "$r" -le 1000 -a $make_exp = "y" ]; do
-    exp=`echo "e($r / 100)" | bc -l "$dir"/math-funcs.bc | fmt --width=500 | tr -d '\\\n ' `
+    exp=`echo "e($r / 100)" | bc -l "$dir"/math-funcs.bc | fmt -w 500 | tr -d '\\\n ' `
     echo "    { .in = $r / 100.0,"
     echo "      .exp = $exp },"
     r=`expr "$r" + "$inc"`
