$NetBSD: patch-src_xfpm-pm-helper.c,v 1.3 2025/01/05 13:50:37 bsiegert Exp $

Add NetBSD support.

--- src/xfpm-pm-helper.c.orig	2024-11-21 06:26:21.000000000 +0000
+++ src/xfpm-pm-helper.c
@@ -82,6 +82,11 @@
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
 #endif
+#ifdef BACKEND_TYPE_NETBSD
+#define UP_BACKEND_SUSPEND_COMMAND "sysctl -w hw.acpi.sleep.state=3"
+#define UP_BACKEND_HIBERNATE_COMMAND "sysctl -w hw.acpi.sleep.state=4"
+#define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
+#endif
 
 
 static gboolean
