$NetBSD: patch-src_gallium_state__trackers_clover_llvm_metadata.hpp,v 1.1 2018/10/07 23:49:31 ryoon Exp $

From FreeBSD ports graphics/libGL mesa 13.0.5

# Fix error: no matching constructor for initialization of 'std::vector<const ::llvm::MDNode *>' 
#

--- src/gallium/state_trackers/clover/llvm/metadata.hpp.orig	2017-02-13 11:55:49.000000000 +0000
+++ src/gallium/state_trackers/clover/llvm/metadata.hpp
@@ -42,7 +42,11 @@ namespace clover {
          get_kernel_nodes(const ::llvm::Module &mod) {
             if (const ::llvm::NamedMDNode *n =
                    mod.getNamedMetadata("opencl.kernels"))
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+               return { n->getOperand(0), n->getOperand(n->getNumOperands()) };
+#else
                return { n->op_begin(), n->op_end() };
+#endif
             else
                return {};
          }
