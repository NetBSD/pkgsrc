$NetBSD: patch-hotspot_src_share_vm_code_relocInfo.hpp,v 1.1 2014/01/20 19:25:11 joerg Exp $

--- hotspot/src/share/vm/code/relocInfo.hpp.orig	2014-01-05 21:21:58.000000000 +0000
+++ hotspot/src/share/vm/code/relocInfo.hpp
@@ -371,7 +371,7 @@ class relocInfo VALUE_OBJ_CLASS_SPEC {
   // "immediate" in the prefix header word itself.  This optimization
   // is invisible outside this module.)
 
-  inline friend relocInfo prefix_relocInfo(int datalen = 0);
+  inline friend relocInfo prefix_relocInfo(int datalen);
 
  protected:
   // an immediate relocInfo optimizes a prefix with one 10-bit unsigned value
@@ -455,6 +455,8 @@ class relocInfo VALUE_OBJ_CLASS_SPEC {
   };
 };
 
+relocInfo prefix_relocInfo(int datalen = 0);
+
 #define FORWARD_DECLARE_EACH_CLASS(name)              \
 class name##_Relocation;
 APPLY_TO_RELOCATIONS(FORWARD_DECLARE_EACH_CLASS)
