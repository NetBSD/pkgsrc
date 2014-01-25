$NetBSD: patch-tools--virsh-secret.c,v 1.1 2014/01/25 02:54:27 agc Exp $

bring forward previous patch to allocate the context with the correct args
"There is a problem expanding the macro in base64.h, so we'll do it here"

--- tools/virsh-secret.c	2014/01/25 01:56:56	1.1
+++ tools/virsh-secret.c	2014/01/25 01:57:41
@@ -212,7 +212,7 @@
     if (vshCommandOptStringReq(ctl, cmd, "base64", &base64) < 0)
         goto cleanup;
 
-    if (!base64_decode_alloc(base64, strlen(base64), &value, &value_size)) {
+    if (!base64_decode_alloc_ctx(NULL, base64, strlen(base64), &value, &value_size)) {
         vshError(ctl, "%s", _("Invalid base64 data"));
         goto cleanup;
     }
