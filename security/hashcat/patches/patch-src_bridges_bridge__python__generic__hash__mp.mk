$NetBSD: patch-src_bridges_bridge__python__generic__hash__mp.mk,v 1.1 2025/08/08 07:23:59 adam Exp $

Use install_name on Darwin.

--- src/bridges/bridge_python_generic_hash_mp.mk.orig	2025-08-05 10:41:50.152896838 +0000
+++ src/bridges/bridge_python_generic_hash_mp.mk
@@ -42,8 +42,13 @@ bridges/bridge_python_generic_hash_mp.dl
 	$(CC_WIN)    $(CCFLAGS) $(CFLAGS_CROSS_WIN)   $^ -o $@ $(LFLAGS_CROSS_WIN)   -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(PYTHON_CFLAGS_WIN)
 else
 ifeq ($(SHARED),1)
+  ifeq ($(UNAME),Darwin)
+bridges/bridge_python_generic_hash_mp.$(BRIDGE_SUFFIX): src/bridges/bridge_python_generic_hash_mp.c src/cpu_features.c $(HASHCAT_LIBRARY)
+	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -install_name $(SHARED_FOLDER)/$@ -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(PYTHON_CFLAGS)
+  else
 bridges/bridge_python_generic_hash_mp.$(BRIDGE_SUFFIX): src/bridges/bridge_python_generic_hash_mp.c src/cpu_features.c $(HASHCAT_LIBRARY)
 	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(PYTHON_CFLAGS)
+  endif
 else
 bridges/bridge_python_generic_hash_mp.$(BRIDGE_SUFFIX): src/bridges/bridge_python_generic_hash_mp.c src/cpu_features.c obj/combined.NATIVE.a
 	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(PYTHON_CFLAGS)
