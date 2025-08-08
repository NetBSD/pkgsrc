$NetBSD: patch-src_bridges_bridge__scrypt__yescrypt.mk,v 1.1 2025/08/08 07:24:00 adam Exp $

Use install_name on Darwin.

--- src/bridges/bridge_scrypt_yescrypt.mk.orig	2025-08-05 10:45:25.876657574 +0000
+++ src/bridges/bridge_scrypt_yescrypt.mk
@@ -21,8 +21,13 @@ bridges/bridge_scrypt_yescrypt.dll: src/
 	$(CC_WIN)   $(CCFLAGS) $(CFLAGS_CROSS_WIN)    $^ -o $@ $(LFLAGS_CROSS_WIN)   -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(SCRYPT_YESCRYPT_CFLAGS)
 else
 ifeq ($(SHARED),1)
+  ifeq ($(UNAME),Darwin)
+bridges/bridge_scrypt_yescrypt.$(BRIDGE_SUFFIX): src/bridges/bridge_scrypt_yescrypt.c src/cpu_features.c $(SCRYPT_YESCRYPT)/yescrypt-opt.c $(SCRYPT_YESCRYPT)/sha256.c $(HASHCAT_LIBRARY)
+	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -install_name $(SHARED_FOLDER)/$@ -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(SCRYPT_YESCRYPT_CFLAGS)
+  else
 bridges/bridge_scrypt_yescrypt.$(BRIDGE_SUFFIX): src/bridges/bridge_scrypt_yescrypt.c src/cpu_features.c $(SCRYPT_YESCRYPT)/yescrypt-opt.c $(SCRYPT_YESCRYPT)/sha256.c $(HASHCAT_LIBRARY)
 	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(SCRYPT_YESCRYPT_CFLAGS)
+  endif
 else
 bridges/bridge_scrypt_yescrypt.$(BRIDGE_SUFFIX): src/bridges/bridge_scrypt_yescrypt.c src/cpu_features.c $(SCRYPT_YESCRYPT)/yescrypt-opt.c $(SCRYPT_YESCRYPT)/sha256.c obj/combined.NATIVE.a
 	$(CC)       $(CCFLAGS) $(CFLAGS_NATIVE)       $^ -o $@ $(LFLAGS_NATIVE)      -shared -fPIC -D BRIDGE_INTERFACE_VERSION_CURRENT=$(BRIDGE_INTERFACE_VERSION) $(SCRYPT_YESCRYPT_CFLAGS)
