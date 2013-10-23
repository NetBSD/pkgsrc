$NetBSD: patch-make_libtool.mk,v 1.3 2013/10/23 09:07:27 wiz Exp $

libtool does not need bash.

--- make/libtool.mk.orig	2013-01-17 14:51:04.000000000 +0000
+++ make/libtool.mk
@@ -1,7 +1,7 @@
 # --- Required interface definitions ---
 
 # LIBTOOL needs bash
-SHELL=/bin/bash
+#SHELL=/bin/bash
 
 OBJ=o
 LOBJ=lo
