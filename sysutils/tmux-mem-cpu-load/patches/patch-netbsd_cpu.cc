$NetBSD: patch-netbsd_cpu.cc,v 1.2 2023/01/19 14:00:35 wiz Exp $

Adapt to signature change.
https://github.com/thewtex/tmux-mem-cpu-load/pull/88

--- netbsd/cpu.cc.orig	2022-03-03 16:23:14.000000000 +0000
+++ netbsd/cpu.cc
@@ -26,12 +26,12 @@
 #include "getsysctl.h"
 #include "cpu.h"
 
-uint8_t get_cpu_count()
+uint32_t get_cpu_count()
 {
   int cpu_count = 0;
   GETSYSCTL( "hw.ncpu", cpu_count );
 
-  return static_cast<uint8_t>( cpu_count );
+  return static_cast<uint32_t>( cpu_count );
 }
 
 float cpu_percentage( unsigned int cpu_usage_delay )
