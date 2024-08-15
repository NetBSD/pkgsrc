$NetBSD: patch-client_Wayland_wlfreerdp.c,v 1.2 2024/08/15 20:41:32 markd Exp $

Support building Wayland components on non-Linux.

gcc14 (incompatible pointer types)

--- client/Wayland/wlfreerdp.c.orig	2024-04-22 09:26:59.000000000 +0000
+++ client/Wayland/wlfreerdp.c
@@ -31,7 +31,9 @@
 #include <freerdp/utils/signal.h>
 #include <freerdp/locale/keyboard.h>
 
+#ifdef __linux
 #include <linux/input.h>
+#endif
 
 #include <uwac/uwac.h>
 
@@ -634,7 +636,7 @@ static BOOL wlf_client_new(freerdp* inst
 		return FALSE;
 
 	obj = ArrayList_Object(wfl->events);
-	obj->fnObjectNew = uwac_event_clone;
+	obj->fnObjectNew = (OBJECT_NEW_FN) uwac_event_clone;
 	obj->fnObjectFree = free;
 
 	InitializeCriticalSection(&wfl->critical);
