$NetBSD: patch-src_xfpm-pm-helper.c,v 1.4 2025/05/10 18:59:47 vins Exp $

Add NetBSD and SunOS support.

--- src/xfpm-pm-helper.c.orig	2024-11-21 06:26:21.000000000 +0000
+++ src/xfpm-pm-helper.c
@@ -82,6 +82,16 @@
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
 #endif
+#ifdef BACKEND_TYPE_NETBSD
+#define UP_BACKEND_SUSPEND_COMMAND "sysctl -w hw.acpi.sleep.state=3"
+#define UP_BACKEND_HIBERNATE_COMMAND "sysctl -w hw.acpi.sleep.state=4"
+#define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
+#endif
+#ifdef BACKEND_TYPE_SOLARIS
+#define UP_BACKEND_SUSPEND_COMMAND "/usr/bin/sys-suspend -x"
+#define UP_BACKEND_HIBERNATE_COMMAND "/usr/bin/false"
+#define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
+#endif
 
 
 static gboolean
