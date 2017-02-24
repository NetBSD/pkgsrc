$NetBSD: patch-va_va.c,v 1.1 2017/02/24 16:44:03 maya Exp $

libva can currently (201702) only use gallium, having tested
for the definition of __vaDriverInit in libraries in DRIVER_SEARCH_PATH
(see package Makefile).

however, it doesn't guess the right driver name for nouveau, so force
it to use gallium.

--- va/va.c.orig	2016-11-10 01:04:28.000000000 +0000
+++ va/va.c
@@ -557,6 +557,17 @@ VAStatus vaInitialize (
         driver_name = strdup(driver_name_env);
         vaStatus = VA_STATUS_SUCCESS;
         va_infoMessage("User requested driver '%s'\n", driver_name);
+    } else {
+	/*
+	 * XXX 201702 only gallium works (provides the required __vaDriverInit)
+	 * XXX but the correct name is not guessed, so force it.
+	 */
+	if (driver_name) /* memory is allocated in va_getDriverName */
+		free(driver_name);
+
+	driver_name = strdup("gallium");
+	vaStatus = VA_STATUS_SUCCESS;
+	va_infoMessage("Using hard-coded gallium driver\n");
     }
 
     if ((VA_STATUS_SUCCESS == vaStatus) && (driver_name != NULL)) {
