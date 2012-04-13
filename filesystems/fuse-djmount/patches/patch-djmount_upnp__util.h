$NetBSD: patch-djmount_upnp__util.h,v 1.1 2012/04/13 23:55:37 obache Exp $

* some definithins had been moved to upnp.h.
* IN/OUT/INOUT in libupnp was deprecated.

--- djmount/upnp_util.h.orig	2006-08-27 20:12:20.000000000 +0000
+++ djmount/upnp_util.h
@@ -27,6 +27,7 @@
 #define UPNP_UTIL_H_INCLUDED
 
 
+#include <upnp/upnp.h>
 #include <upnp/upnptools.h>
 
 
@@ -46,8 +47,8 @@ extern "C" {
  *****************************************************************************/
 char*
 UpnpUtil_GetEventString (void* talloc_context,
-			 IN Upnp_EventType eventType, 
-			 IN const void* event);
+			 Upnp_EventType eventType, 
+			 const void* event);
 
 
 /*****************************************************************************
@@ -55,7 +56,7 @@ UpnpUtil_GetEventString (void* talloc_co
  * @return 	a static constant string, or NULL if unknown event type.
  *****************************************************************************/
 const char*
-UpnpUtil_GetEventTypeString (IN Upnp_EventType e);
+UpnpUtil_GetEventTypeString (Upnp_EventType e);
 
 
 
