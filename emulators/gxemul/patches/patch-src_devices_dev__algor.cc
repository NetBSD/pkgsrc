$NetBSD: patch-src_devices_dev__algor.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/dev_algor.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_algor.cc
@@ -175,17 +175,17 @@ DEVICE_ACCESS(algor)
 			fatal("[ algor: read from 0x%x ]\n",
 			    (int)relative_addr);
 		} else {
-			fatal("[ algor: write to 0x%x: 0x%"PRIx64" ]\n",
+			fatal("[ algor: write to 0x%x: 0x%" PRIx64 " ]\n",
 			    (int) relative_addr, (uint64_t) idata);
 		}
 	}
 
 	if (n != NULL) {
 		if (writeflag == MEM_READ) {
-			debug("[ algor: read from %s: 0x%"PRIx64" ]\n",
+			debug("[ algor: read from %s: 0x%" PRIx64 " ]\n",
 			    n, (uint64_t) odata);
 		} else {
-			debug("[ algor: write to %s: 0x%"PRIx64" ]\n",
+			debug("[ algor: write to %s: 0x%" PRIx64 " ]\n",
 			    n, (uint64_t) idata);
 		}
 	}
@@ -226,4 +226,3 @@ DEVINIT(algor)
 
 	return 1;
 }
-
