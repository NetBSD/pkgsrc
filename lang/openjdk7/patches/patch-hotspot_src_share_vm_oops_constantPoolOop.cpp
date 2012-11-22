$NetBSD: patch-hotspot_src_share_vm_oops_constantPoolOop.cpp,v 1.1 2012/11/22 11:02:05 marino Exp $

Patch taken from upstream: 
SUBJ: Don't return booleans from methods returning pointers
http://hg.openjdk.java.net/hsx/hotspot-rt/hotspot/rev/f457154eee8b

Fixes build on gcc 4.7

--- hotspot/src/share/vm/oops/constantPoolOop.cpp.orig	2011-06-27 16:14:04.000000000 +0000
+++ hotspot/src/share/vm/oops/constantPoolOop.cpp
@@ -269,7 +269,7 @@ klassOop constantPoolOopDesc::klass_ref_
 methodOop constantPoolOopDesc::method_at_if_loaded(constantPoolHandle cpool,
                                                    int which, Bytecodes::Code invoke_code) {
   assert(!constantPoolCacheOopDesc::is_secondary_index(which), "no indy instruction here");
-  if (cpool->cache() == NULL)  return false;  // nothing to load yet
+  if (cpool->cache() == NULL)  return NULL;  // nothing to load yet
   int cache_index = which - CPCACHE_INDEX_TAG;
   if (!(cache_index >= 0 && cache_index < cpool->cache()->length())) {
     if (PrintMiscellaneous && (Verbose||WizardMode)) {
