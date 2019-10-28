$NetBSD: patch-libstark__src__protocols__Ali__prover.cpp,v 1.1 2019/10/28 17:46:58 agc Exp $

NetBSD has no sys/sysinfo.h

--- libstark/src/protocols/Ali/prover.cpp	2019/10/19 04:15:01	1.1
+++ libstark/src/protocols/Ali/prover.cpp	2019/10/19 04:15:57
@@ -6,7 +6,7 @@
 #include "reductions/BairToAcsp/BairToAcsp.hpp"
 
 #include <set>
-#if __GNUG__
+#if __linux__
 #include <sys/sysinfo.h>
 #endif
 
@@ -165,7 +165,7 @@
                 unsigned short logVM;
                 //compute RAM amount on current machine
                 {
-#if __GNUG__
+#if __linux__
                     struct sysinfo info;
                     sysinfo(&info);
                     logRAM = std::floor(Log2(info.totalram));
@@ -585,7 +585,7 @@
             unsigned short logRAM;
             //compute RAM amount on current machine
             {
-#if __GNUG__
+#if __linux__
                 struct sysinfo info;
                 sysinfo(&info);
                 logRAM = Log2(std::round(info.totalram));
