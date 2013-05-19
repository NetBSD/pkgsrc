$NetBSD: patch-js_src_vm_ObjectImpl-inl.h,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- js/src/vm/ObjectImpl-inl.h.orig	2013-05-11 19:19:36.000000000 +0000
+++ js/src/vm/ObjectImpl-inl.h
@@ -164,9 +164,9 @@ js::ObjectImpl::initializeSlotRange(uint
     JSRuntime *rt = runtime();
     uint32_t offset = start;
     for (HeapSlot *sp = fixedStart; sp < fixedEnd; sp++)
-        sp->init(rt, this->asObjectPtr(), HeapSlot::Slot, offset++, UndefinedValue());
+        sp->init(rt, this->asObjectPtr(), HeapSlot::Slot, offset++, js::UndefinedValue());
     for (HeapSlot *sp = slotsStart; sp < slotsEnd; sp++)
-        sp->init(rt, this->asObjectPtr(), HeapSlot::Slot, offset++, UndefinedValue());
+        sp->init(rt, this->asObjectPtr(), HeapSlot::Slot, offset++, js::UndefinedValue());
 }
 
 inline bool
@@ -321,7 +321,7 @@ js::ObjectImpl::sizeOfThis() const
 js::ObjectImpl::readBarrier(ObjectImpl *obj)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapBusy());
         JSObject *tmp = obj->asObjectPtr();
@@ -335,7 +335,7 @@ inline void
 js::ObjectImpl::privateWriteBarrierPre(void **old)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = this->zone();
+    JS::Zone *zone = this->zone();
     if (zone->needsBarrier()) {
         if (*old && getClass()->trace)
             getClass()->trace(zone->barrierTracer(), this->asObjectPtr());
@@ -362,7 +362,7 @@ js::ObjectImpl::writeBarrierPre(ObjectIm
     if (uintptr_t(obj) < 32)
         return;
 
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapBusy());
         JSObject *tmp = obj->asObjectPtr();
