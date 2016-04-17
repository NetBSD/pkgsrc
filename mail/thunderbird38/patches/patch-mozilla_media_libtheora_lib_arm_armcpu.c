$NetBSD: patch-mozilla_media_libtheora_lib_arm_armcpu.c,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/media/libtheora/lib/arm/armcpu.c.orig	2015-06-08 17:49:23.000000000 +0000
+++ mozilla/media/libtheora/lib/arm/armcpu.c
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
