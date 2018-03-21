$NetBSD: patch-src_devices_dev__lca.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/dev_lca.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_lca.cc
@@ -221,7 +221,7 @@ DEVICE_ACCESS(lca_ioc)
 			/*  TODO: Actually implement this.  */
 			if (idata & ~IOC_TB_ENA_TEN) {
 				fatal("TODO: LCA_IOC_TB_ENA value "
-				    " (0x%"PRIx64") has unimplemented "
+				    " (0x%" PRIx64 ") has unimplemented "
 				    "bits.\n", (uint64_t)idata);
 				exit(1);
 			}
@@ -236,7 +236,7 @@ DEVICE_ACCESS(lca_ioc)
 			/*  TODO: Actually implement this.  */
 			if (idata != 0ULL && idata != 0x300800000ULL) {
 				fatal("TODO: LCA_IOC_W_BASE0 value differs"
-				    " (0x%"PRIx64") from the only implemented"
+				    " (0x%" PRIx64 ") from the only implemented"
 				    " values\n", (uint64_t)idata);
 				exit(1);
 			}
@@ -251,7 +251,7 @@ DEVICE_ACCESS(lca_ioc)
 			/*  TODO: Actually implement this.  */
 			if (idata != 0x700000ULL) {
 				fatal("TODO: LCA_IOC_W_MASK0 value differs"
-				    " (0x%"PRIx64") from the only implemented"
+				    " (0x%" PRIx64 ") from the only implemented"
 				    " value\n", (uint64_t)idata);
 				exit(1);
 			}
@@ -275,7 +275,7 @@ DEVICE_ACCESS(lca_ioc)
 			/*  TODO: Actually implement this.  */
 			if (idata != 0x240000000ULL) {
 				fatal("TODO: LCA_IOC_W_BASE1 value differs"
-				    " (0x%"PRIx64") from the only implemented"
+				    " (0x%" PRIx64 ") from the only implemented"
 				    " value\n", (uint64_t)idata);
 				exit(1);
 			}
@@ -290,7 +290,7 @@ DEVICE_ACCESS(lca_ioc)
 			/*  TODO: Actually implement this.  */
 			if (idata != 0x3ff00000ULL) {
 				fatal("TODO: LCA_IOC_W_MASK1 value differs"
-				    " (0x%"PRIx64") from the only implemented"
+				    " (0x%" PRIx64 ") from the only implemented"
 				    " value\n", (uint64_t)idata);
 				exit(1);
 			}
@@ -378,4 +378,3 @@ DEVINIT(lca)
 
 	return 1;
 }
-
