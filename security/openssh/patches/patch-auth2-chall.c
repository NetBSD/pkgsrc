$NetBSD: patch-auth2-chall.c,v 1.1.2.2 2015/08/01 08:56:59 tron Exp $

Fix for CVE-2015-5600 from FreeBSD via NetBSD base.

--- auth2-chall.c.orig	2015-07-01 02:35:31.000000000 +0000
+++ auth2-chall.c
@@ -83,6 +83,7 @@ struct KbdintAuthctxt
 	void *ctxt;
 	KbdintDevice *device;
 	u_int nreq;
+	u_int devices_done;
 };
 
 #ifdef USE_PAM
@@ -169,11 +170,15 @@ kbdint_next_device(Authctxt *authctxt, K
 		if (len == 0)
 			break;
 		for (i = 0; devices[i]; i++) {
-			if (!auth2_method_allowed(authctxt,
+			if ((kbdintctxt->devices_done & (1 << i)) != 0 ||
+			    !auth2_method_allowed(authctxt,
 			    "keyboard-interactive", devices[i]->name))
 				continue;
-			if (strncmp(kbdintctxt->devices, devices[i]->name, len) == 0)
+			if (strncmp(kbdintctxt->devices, devices[i]->name,
+			    len) == 0) {
 				kbdintctxt->device = devices[i];
+				kbdintctxt->devices_done |= 1 << i;
+			}
 		}
 		t = kbdintctxt->devices;
 		kbdintctxt->devices = t[len] ? xstrdup(t+len+1) : NULL;
