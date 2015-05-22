$NetBSD: patch-mono_metadata_mono-perfcounters.c,v 1.2 2015/05/22 06:55:40 kefren Exp $

Correct mibs initialization for NetBSD

--- mono/metadata/mono-perfcounters.c.orig	2015-04-26 19:28:39.000000000 +0300
+++ mono/metadata/mono-perfcounters.c	2015-05-14 19:07:18.000000000 +0300
@@ -33,6 +33,9 @@
 #if defined (__NetBSD__) || defined (__APPLE__)
 #include <sys/sysctl.h>
 #endif
+#if defined(__NetBSD__)
+#include <sys/vmmeter.h>
+#endif
 #include "metadata/mono-perfcounters.h"
 #include "metadata/appdomain.h"
 #include "metadata/object-internals.h"
@@ -473,11 +476,7 @@ mono_determine_physical_ram_available_si
 #elif defined (__NetBSD__)
 	struct vmtotal vm_total;
 	guint64 page_size;
-	int mib [2];
-	size_t len;
-
-
-	mib = {
+	int mib [2] = {
 		CTL_VM,
 #if defined (VM_METER)
 		VM_METER
@@ -485,17 +484,15 @@ mono_determine_physical_ram_available_si
 		VM_TOTAL
 #endif
 	};
-	len = sizeof (vm_total);
+	size_t len = sizeof (vm_total);
 	sysctl (mib, 2, &vm_total, &len, NULL, 0);
 
-	mib = {
-		CTL_HW,
-		HW_PAGESIZE
-	};
+	mib[0] = CTL_HW;
+	mib[1] = HW_PAGESIZE;
 	len = sizeof (page_size);
-	sysctl (mib, 2, &page_size, &len, NULL, 0
+	sysctl (mib, 2, &page_size, &len, NULL, 0);
 
-	return ((guint64) value.t_free * page_size) / 1024;
+	return ((guint64) vm_total.t_free * page_size) / 1024;
 #elif defined (__APPLE__)
 	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
 	vm_statistics_data_t vmstat;
