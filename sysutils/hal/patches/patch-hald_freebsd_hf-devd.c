$NetBSD: patch-hald_freebsd_hf-devd.c,v 1.1 2012/03/31 16:06:56 ryoon Exp $

* From FreeBSD ports repository to fix build on FreeBSD 9.0 RELEASE.

--- hald/freebsd/hf-devd.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/hf-devd.c
@@ -122,7 +122,11 @@ hf_devd_parse_add_remove (const char *ev
   g_return_val_if_fail(parent != NULL, FALSE);
 
   if ((params_ptr = strchr(event, ' '))
+#if defined(__FreeBSD__)
+      && (at_ptr = strstr(params_ptr, "at "))
+#else
       && (at_ptr = strstr(params_ptr + 1, " at "))
+#endif
       && (parent_ptr = strstr(at_ptr + 4, " on ")))
     {
       char *params_str;
@@ -130,7 +134,11 @@ hf_devd_parse_add_remove (const char *ev
 
       *name = g_strndup(event, params_ptr - event);
       params_str = g_strndup(params_ptr + 1, at_ptr - params_ptr - 1);
+#if defined(__FreeBSD__)
+      at_str = g_strndup(at_ptr + 3, parent_ptr - at_ptr - 3);
+#else
       at_str = g_strndup(at_ptr + 4, parent_ptr - at_ptr - 4);
+#endif
       *parent = g_strdup(parent_ptr + 4);
 
       if (! strcmp(*parent, ".")) /* sys/kern/subr_bus.c */
@@ -398,7 +406,11 @@ hf_devd_event_cb (GIOChannel *source, GI
       hf_devd_process_event(event);
       g_free(event);
     }
+#if defined(__FreeBSD__)
+  else if (status == G_IO_STATUS_AGAIN || status == G_IO_STATUS_EOF)
+#else
   else if (status == G_IO_STATUS_AGAIN)
+#endif
     {
       hf_devd_init();
       if (hf_devd_inited)
