$NetBSD: patch-mozilla_ipc_chromium_chromium-config.mk,v 1.4 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/chromium/chromium-config.mk.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/chromium-config.mk
@@ -103,6 +103,14 @@ DEFINES += \
   $(NULL)
 
 else # } {
+ifeq ($(OS_ARCH),SunOS) # {
+
+OS_SOLARIS = 1
+DEFINES += \
+  -DOS_SOLARIS=1 \
+  $(NULL)
+
+else # } {
 
 OS_LINUX = 1
 DEFINES += \
@@ -115,4 +123,5 @@ endif # }
 endif # }
 endif # }
 endif # }
+endif # }
 
