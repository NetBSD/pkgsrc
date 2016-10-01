$NetBSD: patch-vowpalwabbit_accumulate.cc,v 1.1 2016/10/01 13:04:16 joerg Exp $

--- vowpalwabbit/accumulate.cc.orig	2016-09-30 09:24:37.000000000 +0000
+++ vowpalwabbit/accumulate.cc
@@ -9,7 +9,6 @@ Alekh Agarwal and John Langford, with he
 */
 
 #include <iostream>
-#include <sys/timeb.h>
 #include <cmath>
 #include <stdint.h>
 #include "global_data.h"
