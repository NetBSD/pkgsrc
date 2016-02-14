$NetBSD: patch-media_libtheora_lib_arm_armcpu.c,v 1.1 2016/02/14 07:30:54 ryoon Exp $

* NetBSD/evbearmv7hf-el's /proc/cpuinfo return empty, use hardcoded flags.

--- media/libtheora/lib/arm/armcpu.c.orig	2014-11-13 22:50:10.000000000 +0000
+++ media/libtheora/lib/arm/armcpu.c
@@ -107,6 +107,18 @@ ogg_uint32_t oc_cpu_flags_get(void){
   return flags;
 }
 
+#elif defined(__NetBSD__)
+ogg_uint32_t oc_cpu_flags_get(void){
+  ogg_uint32_t  flags;
+  /* XXX ryoon: I have no idea about ARM CPU extensions detection mechanism
+     under NetBSD/earm. 
+     evbearmv6hf-el machine, Raspberry Pi does not have NEON.
+     evbearmv7hf-el machine, CubieBoard2 does not have EDSP.
+     I have no idea about MEDIA.
+     So I will disable all options. */
+  flags=0;
+  return flags;
+}
 #else
 /*The feature registers which can tell us what the processor supports are
    accessible in priveleged modes only, so we can't have a general user-space
