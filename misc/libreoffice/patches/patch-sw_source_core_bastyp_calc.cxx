$NetBSD: patch-sw_source_core_bastyp_calc.cxx,v 1.1 2021/02/06 06:47:24 ryoon Exp $

For NetBSD at least.

--- sw/source/core/bastyp/calc.cxx.orig	2021-01-27 19:33:49.000000000 +0000
+++ sw/source/core/bastyp/calc.cxx
@@ -1080,7 +1080,7 @@ SwSbxValue SwCalc::PrimFunc(bool &rChkPo
             break;
         case CALC_ABS:
             SAL_INFO("sw.calc", "abs");
-            return StdFunc(&abs, false);
+            return StdFunc(&fabs, false);
             break;
         case CALC_SIGN:
         {
