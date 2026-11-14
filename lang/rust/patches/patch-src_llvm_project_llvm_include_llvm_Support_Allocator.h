$NetBSD: patch-src_llvm_project_llvm_include_llvm_Support_Allocator.h,v 1.1 2026/11/14 22:02:08 wiz Exp $

Apply fix from

https://github.com/llvm/llvm-project/commit/0b6b6ed806536c1b170101061ff3eeed91c8f061

in order to fix https://github.com/llvm/llvm-project/issues/230782
which ought to restore our ability to build this rust version for
and on i586 / i686.

--- src/llvm-project/llvm/include/llvm/Support/Allocator.h.orig	2026-10-25 09:13:51.459958720 +0000
+++ src/llvm-project/llvm/include/llvm/Support/Allocator.h
@@ -64,7 +64,7 @@ LLVM_ABI void printBumpPtrAllocatorStats
 /// CurPtr when the requested alignment is no greater than MinAlign.
 template <typename AllocatorT = MallocAllocator, size_t SlabSize = 4096,
           size_t SizeThreshold = SlabSize, size_t GrowthDelay = 128,
-          size_t MinAlign = 8>
+          size_t MinAlign = std::min<size_t>(8, alignof(std::max_align_t))>
 class BumpPtrAllocatorImpl
     : public AllocatorBase<BumpPtrAllocatorImpl<
           AllocatorT, SlabSize, SizeThreshold, GrowthDelay, MinAlign>>,
