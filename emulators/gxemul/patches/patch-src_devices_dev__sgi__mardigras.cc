$NetBSD: patch-src_devices_dev__sgi__mardigras.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/dev_sgi_mardigras.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_sgi_mardigras.cc
@@ -203,7 +203,7 @@ void mardigras_20400(struct cpu *cpu, st
 		return;
 	}
 
-	debug("mardigras_20400(): 0x%016"PRIx64"\n", (uint64_t) idata);
+	debug("mardigras_20400(): 0x%016" PRIx64 "\n", (uint64_t) idata);
 }
 
 
@@ -285,7 +285,7 @@ DEVICE_ACCESS(sgi_mardigras)
 			debug("[ sgi_mardigras: read from 0x%08lx ]\n",
 			    (long)relative_addr);
 		} else {
-			debug("[ sgi_mardigras: write to  0x%08lx: 0x%016"PRIx64
+			debug("[ sgi_mardigras: write to  0x%08lx: 0x%016" PRIx64
 			    " ]\n", (long) relative_addr, (uint64_t) idata);
 		}
 	}
@@ -319,4 +319,3 @@ DEVINIT(sgi_mardigras)
 
 	return 1;
 }
-
