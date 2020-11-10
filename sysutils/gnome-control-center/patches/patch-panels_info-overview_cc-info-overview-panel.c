$NetBSD: patch-panels_info-overview_cc-info-overview-panel.c,v 1.1 2020/11/10 18:22:23 nia Exp $

Avoid udisks dependency, for portability reasons.

--- panels/info-overview/cc-info-overview-panel.c.orig	2020-10-03 22:47:30.420756300 +0000
+++ panels/info-overview/cc-info-overview-panel.c
@@ -38,7 +38,6 @@
 #include <glibtop/mountlist.h>
 #include <glibtop/mem.h>
 #include <glibtop/sysinfo.h>
-#include <udisks/udisks.h>
 
 #include <gdk/gdk.h>
 
@@ -472,6 +471,7 @@ get_os_type (void)
 static void
 get_primary_disc_info (CcInfoOverviewPanel *self)
 {
+#if 0
   g_autoptr(UDisksClient) client = NULL;
   GDBusObjectManager *manager;
   g_autolist(GDBusObject) objects = NULL;
@@ -518,6 +518,9 @@ get_primary_disc_info (CcInfoOverviewPan
     {
       cc_list_row_set_secondary_label (self->disk_row,  _("Unknown"));
     }
+#else
+  cc_list_row_set_secondary_label (self->disk_row,  _("Unknown"));
+#endif
 }
 
 static char *
