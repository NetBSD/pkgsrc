$NetBSD: patch-device-src_device.c,v 1.1 2015/03/27 23:45:29 gdt Exp $

This patch is from upstream, to improve error reporting when amanda is
configured without tape drive support and one tries to use a tape.

--- device-src/device.c.orig	2012-02-21 11:36:44.000000000 +0000
+++ device-src/device.c
@@ -423,17 +423,13 @@ handle_device_regex(const char * user_na
         regfree(&regex);
         return FALSE;
     } else if (reg_result == REG_NOMATCH) {
+        *driver_name = stralloc("tape");
+        *device = stralloc(user_name);
 #ifdef WANT_TAPE_DEVICE
 	g_warning(
 		"\"%s\" uses deprecated device naming convention; \n"
                 "using \"tape:%s\" instead.\n",
                 user_name, user_name);
-        *driver_name = stralloc("tape");
-        *device = stralloc(user_name);
-#else /* !WANT_TAPE_DEVICE */
-	*errmsg = newvstrallocf(*errmsg, "\"%s\" is not a valid device name.\n", user_name);
-	regfree(&regex);
-	return FALSE;
 #endif /* WANT_TAPE_DEVICE */
     } else {
         *driver_name = find_regex_substring(user_name, pmatch[1]);
