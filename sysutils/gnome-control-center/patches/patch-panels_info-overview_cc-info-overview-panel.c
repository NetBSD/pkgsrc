$NetBSD: patch-panels_info-overview_cc-info-overview-panel.c,v 1.2 2021/06/04 11:27:01 cirnatdan Exp $

Avoid udisks dependency, for portability reasons.

--- panels/info-overview/cc-info-overview-panel.c.orig	2021-03-20 21:52:22.999848400 +0000
+++ panels/info-overview/cc-info-overview-panel.c
@@ -38,7 +38,6 @@
 #include <glibtop/mountlist.h>
 #include <glibtop/mem.h>
 #include <glibtop/sysinfo.h>
-#include <udisks/udisks.h>
 
 #include <gdk/gdk.h>
 
@@ -474,6 +473,7 @@ get_os_type (void)
 static void
 get_primary_disc_info (CcInfoOverviewPanel *self)
 {
+#if 0
   g_autoptr(UDisksClient) client = NULL;
   GDBusObjectManager *manager;
   g_autolist(GDBusObject) objects = NULL;
@@ -520,6 +520,9 @@ get_primary_disc_info (CcInfoOverviewPan
     {
       cc_list_row_set_secondary_label (self->disk_row,  _("Unknown"));
     }
+#else
+  cc_list_row_set_secondary_label (self->disk_row,  _("Unknown"));
+#endif
 }
 
 static void
