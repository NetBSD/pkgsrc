$NetBSD: patch-libsanitizer_sanitizer__common_sanitizer__procmaps__mac.cpp,v 1.1 2026/07/19 11:17:45 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- libsanitizer/sanitizer_common/sanitizer_procmaps_mac.cpp.orig	2026-06-12 06:09:10.669588646 +0000
+++ libsanitizer/sanitizer_common/sanitizer_procmaps_mac.cpp
@@ -20,18 +20,21 @@
 #include <mach/mach.h>

 // These are not available in older macOS SDKs.
-#ifndef CPU_SUBTYPE_X86_64_H
-#define CPU_SUBTYPE_X86_64_H  ((cpu_subtype_t)8)   /* Haswell */
-#endif
-#ifndef CPU_SUBTYPE_ARM_V7S
-#define CPU_SUBTYPE_ARM_V7S   ((cpu_subtype_t)11)  /* Swift */
-#endif
-#ifndef CPU_SUBTYPE_ARM_V7K
-#define CPU_SUBTYPE_ARM_V7K   ((cpu_subtype_t)12)
-#endif
-#ifndef CPU_TYPE_ARM64
-#define CPU_TYPE_ARM64        (CPU_TYPE_ARM | CPU_ARCH_ABI64)
-#endif
+#  ifndef CPU_SUBTYPE_X86_64_H
+#    define CPU_SUBTYPE_X86_64_H ((cpu_subtype_t)8) /* Haswell */
+#  endif
+#  ifndef CPU_SUBTYPE_ARM_V7S
+#    define CPU_SUBTYPE_ARM_V7S ((cpu_subtype_t)11) /* Swift */
+#  endif
+#  ifndef CPU_SUBTYPE_ARM_V7K
+#    define CPU_SUBTYPE_ARM_V7K ((cpu_subtype_t)12)
+#  endif
+#  ifndef CPU_TYPE_ARM64
+#    define CPU_TYPE_ARM64 (CPU_TYPE_ARM | CPU_ARCH_ABI64)
+#  endif
+#  ifndef CPU_SUBTYPE_ARM64E
+#    define CPU_SUBTYPE_ARM64E ((cpu_subtype_t)2)
+#  endif

 namespace __sanitizer {

@@ -146,13 +149,8 @@ static bool IsDyldHdr(const mach_header
 // until we hit a Mach header matching dyld instead. These recurse
 // calls are expensive, but the first memory map generation occurs
 // early in the process, when dyld is one of the only images loaded,
-// so it will be hit after only a few iterations.  These assumptions don't
-// hold on macOS 13+ anymore (dyld itself has moved into the shared cache).
-
-// FIXME: Unfortunately, the upstream revised version to deal with macOS 13+
-// is incompatible with GCC and also uses APIs not available on earlier
-// systems which we support; backed out for now.
-
+// so it will be hit after only a few iterations.  These assumptions don't hold
+// on macOS 13+ anymore (dyld itself has moved into the shared cache).
 static mach_header *GetDyldImageHeaderViaVMRegion() {
   vm_address_t address = 0;

@@ -176,17 +174,178 @@ static mach_header *GetDyldImageHeaderVi
   }
 }

+extern "C" {
+struct dyld_shared_cache_dylib_text_info {
+  uint64_t version;  // current version 2
+  // following fields all exist in version 1
+  uint64_t loadAddressUnslid;
+  uint64_t textSegmentSize;
+  uuid_t dylibUuid;
+  const char *path;  // pointer invalid at end of iterations
+  // following fields all exist in version 2
+  uint64_t textSegmentOffset;  // offset from start of cache
+};
+typedef struct dyld_shared_cache_dylib_text_info
+    dyld_shared_cache_dylib_text_info;
+
+extern bool _dyld_get_shared_cache_uuid(uuid_t uuid);
+extern const void *_dyld_get_shared_cache_range(size_t *length);
+extern intptr_t _dyld_get_image_slide(const struct mach_header* mh);
+} // extern "C"
+
+#ifdef __BLOCKS__
+extern "C" {
+extern int dyld_shared_cache_iterate_text(
+    const uuid_t cacheUuid,
+    void (^callback)(const dyld_shared_cache_dylib_text_info *info));
+}  // extern "C"
+
+static mach_header *GetDyldImageHeaderViaSharedCache(uuid_t uuid) {
+  size_t cacheLength;
+  const uptr cacheStart = (uptr)_dyld_get_shared_cache_range(&cacheLength);
+  CHECK(cacheStart && cacheLength);
+
+  __block mach_header *dyldHdr = nullptr;
+  int res = dyld_shared_cache_iterate_text(
+      uuid, ^(const dyld_shared_cache_dylib_text_info *info) {
+        CHECK_GE(info->version, 2);
+        mach_header *hdr =
+            (mach_header *)(cacheStart + info->textSegmentOffset);
+        if (IsDyldHdr(hdr))
+          dyldHdr = hdr;
+      });
+  CHECK_EQ(res, 0);
+
+  return dyldHdr;
+}
+
+#else
+
+/* Here we implement a manual emulation of the Blocks closure and callback
+   that is needed by dyld_shared_cache_iterate_text ().  In the compiler-
+   generated code, the [local] names are mangled differently, but that
+   should not matter to the function (since all the entities are TU-local).  */
+
+extern "C" {
+/* Some descriptions of the blocks interfaces/runtime that we need.  */
+extern void *_NSConcreteStackBlock;
+extern void _Block_object_assign(void *, void *, int);
+extern void _Block_object_dispose(void *, int);
+enum {
+  BLOCK_FIELD_IS_OBJECT   =  3,  /* id, NSObject, __attribute__((NSObject)), block, ... */
+  BLOCK_FIELD_IS_BLOCK    =  7,  /* a block variable */
+  BLOCK_FIELD_IS_BYREF    =  8,  /* the on stack structure holding the __block variable */
+  BLOCK_FIELD_IS_WEAK     = 16,  /* declared __weak, only used in byref copy helpers */
+  BLOCK_BYREF_CALLER      = 128  /* called from __block (byref) copy/dispose support routines. */
+};
+
+/* 1. __block mach_header *dyldHdr; Uses this on-stack object.  */
+typedef struct __block_byref_dyldHdr {
+    void *__isa;
+    struct __block_byref_dyldHdr *forwarding;
+    int flags;   // 1<<25 iff we need copy helper;
+    int size;
+    mach_header *dyldHdr_cp;
+} dyldHdr_type;
+
+/* The closure, support functions and the actuall callback code.  */
+/* 1. closure descriptor.  A constant instance of this will be created.  */
+struct Block_descriptor_cb {
+  unsigned long int reserved;     // NULL
+  unsigned long int size;         // sizeof(struct Block_literal_cb)
+  // optional helper functions
+  void (*copy_helper)(struct Block_literal_cb *dst, struct Block_literal_cb *src);     // IFF (1<<25)
+  void (*dispose_helper)(struct Block_literal_cb *src);             // IFF (1<<25)
+  // required ABI.2010.3.16
+  const char *signature;                         // IFF (1<<30)
+  void *no_idea; // not documented in the current ABI
+};
+
+/* 2. This is the closure object.  In this case, it will be allocated on the
+      stack and does not need to be moved (since the closure never escapes
+      from its enclosing scope).  However, the infrastructure still provides
+      support for moving it to the heap if required.  */
+typedef struct Block_literal_cb {
+  void *__isa;
+  int flags;
+  int reserved;
+  void (*invoke) (Block_literal_cb*, const dyld_shared_cache_dylib_text_info *info);
+  const struct Block_descriptor_cb *descriptor;
+  dyldHdr_type *h_holder;
+  uptr cache_start;
+} CallbackBlk;
+
+/* 3. Supporting functions to allow for the closure to be copied to the heap on
+   demand.  */
+static void
+__block_copy_cb (struct Block_literal_cb *dst, struct Block_literal_cb *src)
+{
+  //_Block_byref_assign_copy(&dst->captured_i, src->captured_i);
+  _Block_object_assign(&dst->h_holder, src->h_holder, BLOCK_FIELD_IS_BYREF);
+}
+
+static void
+__block_dispose_cb (struct Block_literal_cb *src) {
+   //_Block_byref_release(src->captured_i);
+  _Block_object_dispose(src->h_holder, BLOCK_FIELD_IS_BYREF);
+}
+
+/* 4. Here is the actual code implementing the callback.  */
+static void
+__block_invoke_cb (struct Block_literal_cb *_block,
+		   const dyld_shared_cache_dylib_text_info *info)
+{
+  mach_header *hdr = (mach_header *)(_block->cache_start + info->textSegmentOffset);
+  if (IsDyldHdr(hdr))
+    _block->h_holder->forwarding->dyldHdr_cp = hdr;
+}
+
+/* 6. The constant instance of the descriptor mentioned in 1 above.  */
+static const struct Block_descriptor_cb cb_descr = {
+    0, sizeof (struct Block_literal_cb), __block_copy_cb, __block_dispose_cb,
+    "v16@?0r^{dyld_shared_cache_dylib_text_info=QQQ[16C]*Q}8", nullptr
+};
+
+/* Declare dyld_shared_cache_iterate_text () as taking a regular pointer to
+   the closure; we cannot use the ^ syntax yet in GCC.  */
+extern int dyld_shared_cache_iterate_text(const uuid_t cacheUuid, CallbackBlk*);
+}  // extern "C"
+
+/* The non-blocks version of GetDyldImageHeaderViaSharedCache ().  */
+static mach_header *GetDyldImageHeaderViaSharedCache(uuid_t uuid) {
+  size_t cacheLength;
+  const uptr cacheStart = (uptr)_dyld_get_shared_cache_range(&cacheLength);
+  CHECK(cacheStart && cacheLength);
+  /* __block mach_header *dyldHdr = nullptr; */
+  dyldHdr_type dyldHdr
+    = { nullptr, &dyldHdr, 0, sizeof (struct __block_byref_dyldHdr), nullptr };
+  /* Callback cb = ^(const dyld_shared_cache_dylib_text_info *info... */
+  CallbackBlk cb
+    = { _NSConcreteStackBlock, 0x42000000, 0, __block_invoke_cb,
+        &cb_descr, &dyldHdr, cacheStart };
+  int res = dyld_shared_cache_iterate_text ( uuid, &cb );
+  CHECK_EQ(res, 0);
+  return dyldHdr.forwarding->dyldHdr_cp;
+}
+#endif
+
 const mach_header *get_dyld_hdr() {
   if (!dyld_hdr) {
     // On macOS 13+, dyld itself has moved into the shared cache.  Looking it up
     // via vm_region_recurse_64() causes spins/hangs/crashes.
-    // FIXME: find a way to do this compatible with GCC.
     if (GetMacosAlignedVersion() >= MacosVersion(13, 0)) {
+      uuid_t uuid;
+      if (!_dyld_get_shared_cache_uuid(uuid))
+        VReport(1, "Failed get the shared cache on macOS 13+\n");
+      else
+        dyld_hdr = GetDyldImageHeaderViaSharedCache(uuid);
+      if (!dyld_hdr) {
         VReport(1,
-                "looking up the dyld image header in the shared cache on "
-                "macOS 13+ is not yet supported.  Falling back to "
+                "Failed to lookup the dyld image header in the shared cache on "
+                "macOS 13+ (or no shared cache in use).  Falling back to "
                 "lookup via vm_region_recurse_64().\n");
         dyld_hdr = GetDyldImageHeaderViaVMRegion();
+      }
     } else {
       dyld_hdr = GetDyldImageHeaderViaVMRegion();
     }
@@ -213,6 +372,13 @@ static bool NextSegmentLoad(MemoryMapped
   layout_data->current_load_cmd_count--;
   if (((const load_command *)lc)->cmd == kLCSegment) {
     const SegmentCommand* sc = (const SegmentCommand *)lc;
+    if (internal_strcmp(sc->segname, "__LINKEDIT") == 0) {
+      // The LINKEDIT sections are for internal linker use, and may alias
+      // with the LINKEDIT section for other modules. (If we included them,
+      // our memory map would contain overlappping sections.)
+      return false;
+    }
+
     uptr base_virt_addr, addr_mask;
     if (layout_data->current_image == kDyldImageIdx) {
       base_virt_addr = (uptr)get_dyld_hdr();
@@ -281,6 +447,8 @@ ModuleArch ModuleArchFromCpuType(cpu_typ
       CHECK(0 && "Invalid subtype of ARM");
       return kModuleArchUnknown;
     case CPU_TYPE_ARM64:
+      if (cpusubtype == CPU_SUBTYPE_ARM64E)
+        return kModuleArchARM64E;
       return kModuleArchARM64;
     default:
       CHECK(0 && "Invalid CPU type");
