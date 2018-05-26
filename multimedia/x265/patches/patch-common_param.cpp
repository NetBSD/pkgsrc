$NetBSD: patch-common_param.cpp,v 1.1 2018/05/26 05:30:20 jklos Exp $

--- common/param.cpp.orig	2018-05-21 08:33:10.000000000 +0000
+++ common/param.cpp
@@ -633,7 +633,7 @@ int x265_param_parse(x265_param* p, cons
         if (bValueWasNull)
             p->cpuid = atobool(value);
         else
-            p->cpuid = parseCpuName(value, bError);
+            p->cpuid = parseCpuName(value, bError, 0);
 #endif
     }
     OPT("fps")
