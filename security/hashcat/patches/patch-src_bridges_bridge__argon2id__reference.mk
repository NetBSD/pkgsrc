$NetBSD: patch-src_bridges_bridge__argon2id__reference.mk,v 1.1 2025/08/08 07:23:59 adam Exp $

Use install_name on Darwin.

--- src/bridges/bridge_argon2id_reference.mk.orig	2025-08-05 10:39:06.794007881 +0000
+++ src/bridges/bridge_argon2id_reference.mk
@@ -21,8 +21,13 @@ bridges/bridge_argon2id_reference.dll: s
 	$(CC_WIN)   $(CCFLAGS) $(CFLAGS_CROSS_WIN)    $^ -o $@ $(LFLAGS_CROSS_WIN)   -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(ARGON2_REFERENCE_CFLAGS)
 else
 ifeq ($(SHARED),1)
+  ifeq ($(UNAME),Darwin)
+bridges/bridge_argon2id_reference.$(BRIDGE_SUFFIX): src/bridges/bridge_argon2id_reference.c src/cpu_features.c $(HASHCAT_LIBRARY)
+	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -install_name $(SHARED_FOLDER)/$@ -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(ARGON2_REFERENCE_CFLAGS)
+  else
 bridges/bridge_argon2id_reference.$(BRIDGE_SUFFIX): src/bridges/bridge_argon2id_reference.c src/cpu_features.c $(HASHCAT_LIBRARY)
 	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(ARGON2_REFERENCE_CFLAGS)
+  endif
 else
 bridges/bridge_argon2id_reference.$(BRIDGE_SUFFIX): src/bridges/bridge_argon2id_reference.c src/cpu_features.c obj/combined.NATIVE.a
 	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(ARGON2_REFERENCE_CFLAGS)
