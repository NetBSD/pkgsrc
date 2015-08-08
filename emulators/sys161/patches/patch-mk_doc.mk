$NetBSD: patch-mk_doc.mk,v 1.1 2015/08/08 18:44:32 dholland Exp $

--- mk/doc.mk~	2015-08-05 04:18:46.000000000 +0000
+++ mk/doc.mk
@@ -3,7 +3,7 @@
 #
 
 HTML=devices.html gdb.html index.html install.html lamebus.html \
-     mips.html networking.html system.html
+     mips.html networking.html prof.html system.html
 
 
 include defs.mk
