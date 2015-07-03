$NetBSD: patch-hotspot_src_os_solaris_dtrace_jhelper.d,v 1.1 2015/07/03 20:40:59 fhajny Exp $

GCC support.

--- hotspot/src/os/solaris/dtrace/jhelper.d.orig	2015-06-10 10:31:52.000000000 +0000
+++ hotspot/src/os/solaris/dtrace/jhelper.d
@@ -43,12 +43,33 @@
 
 extern pointer __JvmOffsets;
 
-extern pointer __1cJCodeCacheF_heap_;
-extern pointer __1cIUniverseO_collectedHeap_;
-
-extern pointer __1cHnmethodG__vtbl_;
-extern pointer __1cGMethodG__vtbl_;
-extern pointer __1cKBufferBlobG__vtbl_;
+/* name mangling depends on the compiler used */
+#ifndef _GNU_SOURCE
+#define SYMBOL_JCODECACHE_HEAP	__1cJCodeCacheF_heap_
+#define SYMBOL_UNIVERSE_METHODKLASSOBJ	__1cIUniverseP_methodKlassObj_
+#define SYMBOL_UNIVERSE_COLLECTEDHEAP	__1cIUniverseO_collectedHeap_
+#define SYMBOL_UNIVERSE_NARROW_OOP	__1cIUniverseL_narrow_oop_
+#define SYMBOL_NMETHOD_VTBL	__1cHnmethodG__vtbl_
+#define SYMBOL_METHOD_VTBL	__1cGMethodG__vtbl_
+#define SYMBOL_BUFFERBLOB_VTBL	__1cKBufferBlobG__vtbl_
+#else
+#define SYMBOL_JCODECACHE_HEAP	_ZN9CodeCache5_heapE
+#define SYMBOL_UNIVERSE_METHODKLASSOBJ	_ZN8Universe15_methodKlassObjE
+#define SYMBOL_UNIVERSE_COLLECTEDHEAP	_ZN8Universe14_collectedHeapE
+#define SYMBOL_UNIVERSE_NARROW_OOP	_ZN8Universe11_narrow_oopE
+#define SYMBOL_NMETHOD_VTBL	_ZTV7nmethod
+#define SYMBOL_METHOD_VTBL	_ZTV6Method
+#define SYMBOL_BUFFERBLOB_VTBL	_ZTV10BufferBlob
+#endif /* ! _GNU_SOURCE */
+
+extern pointer SYMBOL_JCODECACHE_HEAP;
+extern pointer SYMBOL_UNIVERSE_METHODKLASSOBJ;
+extern pointer SYMBOL_UNIVERSE_COLLECTEDHEAP;
+extern pointer SYMBOL_UNIVERSE_NARROW_OOP;
+
+extern pointer SYMBOL_NMETHOD_VTBL;
+extern pointer SYMBOL_METHOD_VTBL;
+extern pointer SYMBOL_BUFFERBLOB_VTBL;
 
 #define copyin_ptr(ADDR)    *(pointer*)  copyin((pointer) (ADDR), sizeof(pointer))
 #define copyin_uchar(ADDR)  *(uchar_t*)  copyin((pointer) (ADDR), sizeof(uchar_t))
@@ -152,7 +173,7 @@ dtrace:helper:ustack:
 #error "Don't know architecture"
 #endif
 
-  this->CodeCache_heap_address = copyin_ptr(&``__1cJCodeCacheF_heap_);
+  this->CodeCache_heap_address = copyin_ptr(&``SYMBOL_JCODECACHE_HEAP);
 
   this->CodeCache_low = copyin_ptr(this->CodeCache_heap_address + 
       OFFSET_CodeHeap_memory + OFFSET_VirtualSpace_low);
@@ -169,12 +190,12 @@ dtrace:helper:ustack:
   this->CodeHeap_log2_segment_size = copyin_uint32(
       this->CodeCache_heap_address + OFFSET_CodeHeap_log2_segment_size);
 
-  this->Method_vtbl             = (pointer) &``__1cGMethodG__vtbl_;
+  this->Method_vtbl             = (pointer) &``SYMBOL_METHOD_VTBL;
 
   /*
    * Get Java heap bounds
    */
-  this->Universe_collectedHeap = copyin_ptr(&``__1cIUniverseO_collectedHeap_);
+  this->Universe_collectedHeap = copyin_ptr(&``SYMBOL_UNIVERSE_COLLECTEDHEAP);
   this->heap_start = copyin_ptr(this->Universe_collectedHeap +
       OFFSET_CollectedHeap_reserved +
       OFFSET_MemRegion_start);
@@ -275,8 +296,8 @@ dtrace:helper:ustack:
   this->start = this->block + SIZE_HeapBlockHeader;
   this->vtbl = copyin_ptr(this->start);
 
-  this->nmethod_vtbl            = (pointer) &``__1cHnmethodG__vtbl_;
-  this->BufferBlob_vtbl         = (pointer) &``__1cKBufferBlobG__vtbl_;
+  this->nmethod_vtbl            = (pointer) &``SYMBOL_NMETHOD_VTBL;
+  this->BufferBlob_vtbl         = (pointer) &``SYMBOL_BUFFERBLOB_VTBL;
 }
 
 dtrace:helper:ustack:
