$NetBSD: patch-make_libtool.mk,v 1.4 2020/12/24 20:35:25 yhardy Exp $

libtool does not need bash.

make the libtool tags explicit (fixes compiling on NetBSD/i386).

--- make/libtool.mk.orig	2020-10-27 15:57:48.000000000 +0000
+++ make/libtool.mk
@@ -1,7 +1,7 @@
 # --- Required interface definitions ---
 
 # LIBTOOL needs bash
-SHELL=/bin/bash
+#SHELL=/bin/bash
 
 OBJ=o
 LOBJ=lo
@@ -60,7 +60,7 @@ endef
 #                          1   2
 # Usage: $(call libcompile,src,includes)
 define libcompile
-	$(LIBTOOL) --quiet --mode=compile \
+	$(LIBTOOL) --quiet --mode=compile --tag=CXX \
 		$(CXX) $(CXXFLAGS) \
 		$(call libdepflags,$(basename $(call src_to_obj,$(1)))) \
 		$(foreach I,$(2),-I$(I)) \
@@ -72,7 +72,7 @@ endef
 #                          1   2
 # Usage: $(call libcompile,src,includes)
 define c_libcompile
-	$(LIBTOOL) --quiet --mode=compile \
+	$(LIBTOOL) --quiet --mode=compile --tag=CC \
 		$(CC) $(CFLAGS) \
 		$(call libdepflags,$(basename $(call c_src_to_obj,$(1)))) \
 		$(foreach I,$(2),-I$(I)) \
