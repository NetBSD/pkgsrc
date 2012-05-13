$NetBSD: patch-src_core.c,v 1.1.1.1 2012/05/13 08:42:20 imil Exp $

Enable NetBSD as a suitable platform.

--- src/core.c.orig	2012-05-03 21:08:27.000000000 +0000
+++ src/core.c
@@ -65,7 +65,7 @@
 #include "top.h"
 
 #ifdef NCURSES
-#include <ncurses.h>
+#include <curses.h>
 #endif
 
 /* check for OS and include appropriate headers */
@@ -75,6 +75,8 @@
 #include "freebsd.h"
 #elif defined(__OpenBSD__)
 #include "openbsd.h"
+#elif defined(__NetBSD__)
+#include "netbsd.h"
 #endif
 
 #include <string.h>
@@ -237,7 +239,7 @@ struct text_object *construct_text_objec
 
 #endif /* __linux__ */
 
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__)
 	END OBJ(acpifan, 0)
 	END OBJ(battery, 0)
 		char bat[64];
@@ -326,10 +328,8 @@ struct text_object *construct_text_objec
 			obj->data.i = PB_BATT_STATUS;
 		}
 #endif /* __linux__ */
-#if (defined(__FreeBSD__) || defined(__linux__))
 	END OBJ_IF_ARG(if_up, 0, "if_up needs an argument")
 		parse_if_up_arg(obj, arg);
-#endif
 #if defined(__OpenBSD__)
 	END OBJ_ARG(obsd_sensors_temp, 0, "obsd_sensors_temp: needs an argument")
 		parse_obsd_sensor(obj, arg);
@@ -860,7 +860,7 @@ struct text_object *construct_text_objec
 	END OBJ(gw_ip, &update_gateway_info)
 #endif /* !__linux__ */
 #if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
-		|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))
+	|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))
 	END OBJ(apm_adapter, 0)
 	END OBJ(apm_battery_life, 0)
 	END OBJ(apm_battery_time, 0)
@@ -1371,7 +1371,7 @@ void free_text_objects(struct text_objec
 	for (obj = root->prev; obj; obj = root->prev) {
 		root->prev = obj->prev;
 		switch (obj->type) {
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__)
 			case OBJ_acpitemp:
 				close(data.i);
 				break;
@@ -1645,7 +1645,7 @@ void free_text_objects(struct text_objec
 #endif /* HAVE_LUA */
 			case OBJ_pre_exec:
 				break;
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__)
 			case OBJ_battery:
 				free(data.s);
 				break;
