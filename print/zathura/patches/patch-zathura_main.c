$NetBSD: patch-zathura_main.c,v 1.3 2024/08/10 07:50:33 adam Exp $

Use correct function name.

--- zathura/main.c.orig	2024-08-10 07:18:20.881439447 +0000
+++ zathura/main.c
@@ -289,7 +289,7 @@ GIRARA_VISIBLE int main(int argc, char*
   {
     const gchar* id = gtkosx_application_get_bundle_id();
     if (id != NULL) {
-      girara_warn("TestIntegration Error! Bundle has ID %s", id);
+      girara_warning("TestIntegration Error! Bundle has ID %s", id);
     }
   }
 #endif // GTKOSXAPPLICATION
