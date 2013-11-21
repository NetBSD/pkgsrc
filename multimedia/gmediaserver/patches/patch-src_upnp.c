$NetBSD: patch-src_upnp.c,v 1.2 2013/11/21 09:05:08 obache Exp $

* API change for libupnp>=1.6.7

--- src/upnp.c.orig	2007-10-28 08:20:43.000000000 +0000
+++ src/upnp.c
@@ -25,6 +25,7 @@
 #include <assert.h>		/* C89 */
 #include <netinet/in.h>		/* ?; inet_ntoa */
 #include <arpa/inet.h>		/* ?; inet_ntoa */
+#include <netdb.h>
 #include <inttypes.h>		/* POSIX */
 #include "gettext.h"            /* Gnulib/gettext */
 #define _(s) gettext(s)
@@ -61,6 +62,32 @@ static Service services[] = {
   { 0, }
 };
 
+static void
+say_ip_addr(int level, const char* header, struct sockaddr_storage* addr)
+{
+  char hbuf[NI_MAXHOST];
+  int err;
+  int slen;
+#ifdef __sun
+  switch (addr->ss_family) {
+  case AF_INET:
+    slen = sizeof (struct sockaddr_in);
+    break;
+  case AF_INET6:
+    slen = sizeof (struct sockaddr_in6);
+    break;
+  default:
+    slen = sizeof(*addr);
+    break;
+  }
+#else
+  slen = addr->ss_len;
+#endif
+  err = getnameinfo((struct sockaddr*)addr, slen, hbuf, NI_MAXHOST,
+		    NULL, 0, NI_NUMERICHOST);
+  say(level, header, err == 0 ? hbuf : "(unknown)");
+}
+
 static const char *
 upnp_errmsg(int res)
 {
@@ -265,7 +292,7 @@ handle_get_var_request(struct Upnp_State
     say(3, _("Event device UDN: %s\n"), quotearg(request->DevUDN));
     say(3, _("Event service ID: %s\n"), quotearg(request->ServiceID));
     say(3, _("Event variable name: %s\n"), quotearg(request->StateVarName));
-    say(3, _("Event source: %s\n"), inet_ntoa(request->CtrlPtIPAddr));
+    say_ip_addr(3, _("Event source: %s\n"), &request->CtrlPtIPAddr);
 
     if (strcmp(request->DevUDN, device_udn) != 0) {
         say(1, _("Discarding event - event device UDN (%s) not recognized\n"), quotearg(request->DevUDN));
@@ -306,7 +333,7 @@ handle_action_request(struct Upnp_Action
     say(3, _("Event device UDN: %s\n"), quotearg(request->DevUDN));
     say(3, _("Event service ID: %s\n"), quotearg(request->ServiceID));
     say(3, _("Event action name: %s\n"), quotearg(request->ActionName));
-    say(3, _("Event source: %s\n"), inet_ntoa(request->CtrlPtIPAddr));
+    say_ip_addr(3, _("Event source: %s\n"), &request->CtrlPtIPAddr);
     say_document(4, _("Event action request:\n"), request->ActionRequest);
 
     if (strcmp(request->DevUDN, device_udn) != 0) {
