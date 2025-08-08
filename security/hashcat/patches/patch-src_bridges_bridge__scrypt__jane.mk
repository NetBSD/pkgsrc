$NetBSD: patch-src_bridges_bridge__scrypt__jane.mk,v 1.1 2025/08/08 07:24:00 adam Exp $

Use install_name on Darwin.

--- src/bridges/bridge_scrypt_jane.mk.orig	2025-08-05 10:44:21.320567280 +0000
+++ src/bridges/bridge_scrypt_jane.mk
@@ -21,8 +21,13 @@ bridges/bridge_scrypt_jane.dll: src/brid
 	$(CC_WIN)   $(CCFLAGS) $(CFLAGS_CROSS_WIN)    $^ -o $@ $(LFLAGS_CROSS_WIN)   -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(SCRYPT_JANE_CFLAGS)
 else
 ifeq ($(SHARED),1)
+  ifeq ($(UNAME),Darwin)
+bridges/bridge_scrypt_jane.$(BRIDGE_SUFFIX): src/bridges/bridge_scrypt_jane.c src/cpu_features.c $(HASHCAT_LIBRARY)
+	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -install_name $(SHARED_FOLDER)/$@ -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(SCRYPT_JANE_CFLAGS)
+  else
 bridges/bridge_scrypt_jane.$(BRIDGE_SUFFIX): src/bridges/bridge_scrypt_jane.c src/cpu_features.c $(HASHCAT_LIBRARY)
 	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(SCRYPT_JANE_CFLAGS)
+  endif
 else
 bridges/bridge_scrypt_jane.$(BRIDGE_SUFFIX): src/bridges/bridge_scrypt_jane.c src/cpu_features.c obj/combined.NATIVE.a
 	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(SCRYPT_JANE_CFLAGS)
