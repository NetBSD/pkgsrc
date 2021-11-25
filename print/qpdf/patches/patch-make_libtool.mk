$NetBSD: patch-make_libtool.mk,v 1.5 2021/11/25 15:06:48 ryoon Exp $

libtool does not need bash.

--- make/libtool.mk.orig	2020-10-27 15:57:48.000000000 +0000
+++ make/libtool.mk
@@ -1,7 +1,7 @@
 # --- Required interface definitions ---
 
 # LIBTOOL needs bash
-SHELL=/bin/bash
+#SHELL=/bin/bash
 
 OBJ=o
 LOBJ=lo
