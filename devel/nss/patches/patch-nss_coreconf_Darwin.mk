$NetBSD: patch-nss_coreconf_Darwin.mk,v 1.1 2017/02/02 07:25:44 yyamano Exp $

Always use the sqlite3 library in NSS to avoid installation error on Mac OS X.

--- nss/coreconf/Darwin.mk.orig	2017-01-04 14:24:24.000000000 +0000
+++ nss/coreconf/Darwin.mk
@@ -134,17 +134,19 @@ ZLIB_LIBS	= -lz
 # the NSS libsqlite3.dylib is used instead of the system one. So just use the
 # system sqlite library on Mac, if it's sufficiently new.
 
-SYS_SQLITE3_VERSION_FULL := $(shell /usr/bin/sqlite3 -version | awk '{print $$1}')
-SYS_SQLITE3_VERSION_MAJOR := $(shell echo $(SYS_SQLITE3_VERSION_FULL) | awk -F. '{ print $$1 }')
-SYS_SQLITE3_VERSION_MINOR := $(shell echo $(SYS_SQLITE3_VERSION_FULL) | awk -F. '{ print $$2 }')
-
-ifeq (3,$(SYS_SQLITE3_VERSION_MAJOR))
-    ifeq (,$(filter-out 0 1 2 3 4,$(SYS_SQLITE3_VERSION_MINOR)))
-        # sqlite <= 3.4.x is too old, it doesn't provide sqlite3_file_control
-    else
-        NSS_USE_SYSTEM_SQLITE = 1
-    endif
-endif
+# Always use the library in NSS, just like other platforms.
+#
+#SYS_SQLITE3_VERSION_FULL := $(shell /usr/bin/sqlite3 -version | awk '{print $$1}')
+#SYS_SQLITE3_VERSION_MAJOR := $(shell echo $(SYS_SQLITE3_VERSION_FULL) | awk -F. '{ print $$1 }')
+#SYS_SQLITE3_VERSION_MINOR := $(shell echo $(SYS_SQLITE3_VERSION_FULL) | awk -F. '{ print $$2 }')
+#
+#ifeq (3,$(SYS_SQLITE3_VERSION_MAJOR))
+#    ifeq (,$(filter-out 0 1 2 3 4,$(SYS_SQLITE3_VERSION_MINOR)))
+#        # sqlite <= 3.4.x is too old, it doesn't provide sqlite3_file_control
+#    else
+#        NSS_USE_SYSTEM_SQLITE = 1
+#    endif
+#endif
 
 include $(CORE_DEPTH)/coreconf/sanitizers.mk
 DARWIN_SDK_SHLIBFLAGS += $(SANITIZER_LDFLAGS)
