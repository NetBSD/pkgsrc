$NetBSD: patch-panel-plugin_battery.c,v 1.3 2018/11/25 20:55:42 martin Exp $

Fix for NetBSD.

--- panel-plugin/battery.c.orig	2016-10-29 08:37:38.000000000 +0200
+++ panel-plugin/battery.c	2018-11-25 21:49:59.741230700 +0100
@@ -26,13 +26,28 @@
 #include <config.h>
 #endif
 
-#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && (defined(i386) || defined(__i386__))
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/ioctl.h>
+#include <dev/apm/apmbios.h>
+#include <dev/apm/apmio.h>
+#define APMDEVICE "/dev/apm"
+#define _ACPI_APM_BATT_UNKNOWN	0xffff /* from sys/dev/acpi/acpi_apm.c */
+#elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && (defined(i386) || defined(__i386__))
 #include <machine/apm_bios.h>
-#elif (defined(__OpenBSD__) || defined(__NetBSD__))
+#elif (defined(__OpenBSD__)
 #include <sys/param.h>
 #include <sys/ioctl.h>
+#if defined(__sparc64__)
+#include <sparc/apmvar.h>
+#elif defined(__x86_64__)
+#include <dev/apm/apmbios.h>
+#include <dev/apm/apmio.h>
+#else
 #include <machine/apmvar.h>
+#endif
 #define APMDEVICE "/dev/apm"
+#define _ACPI_APM_BATT_UNKNOWN	0xffff /* from sys/dev/acpi/acpi_apm.c */
 #elif __linux__
 #include <libapm.h>
 #endif
@@ -162,7 +177,7 @@ init_options(t_battmon_options *options)
 gboolean
 detect_battery_info(t_battmon *battmon)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
   /* This is how I read the information from the APM subsystem under
      FreeBSD.  Each time this functions is called (once every second)
      the APM device is opened, read from and then closed.
@@ -401,7 +416,7 @@ update_apm_status(t_battmon *battmon)
         acline = apm.ac_line_status ? TRUE : FALSE;
 
     }
-#elif __FreeBSD__
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
     else {
  /* This is how I read the information from the APM subsystem under
      FreeBSD.  Each time this functions is called (once every second)
@@ -500,6 +515,11 @@ battmon.c:241: for each function it appe
     if(battmon->options.display_percentage && charge > 0 && !(battmon->options.hide_when_full && acline && charge >= 99)){
         gtk_widget_show(GTK_WIDGET(battmon->charge));
         gtk_widget_show(GTK_WIDGET(battmon->timechargealignment));
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+	if (apm.battery_state == APM_BATT_ABSENT)
+		g_snprintf(buffer, sizeof(buffer), "--%%");
+	else
+#endif
         g_snprintf(buffer, sizeof(buffer),"%d%% ", charge);
         gtk_label_set_text(battmon->charge,buffer);
     } else {
@@ -509,6 +529,10 @@ battmon.c:241: for each function it appe
     if (battmon->options.display_time && time_remaining > 0 && !(battmon->options.hide_when_full && acline && charge >= 99 )){
         gtk_widget_show(GTK_WIDGET(battmon->rtime));
         gtk_widget_show(GTK_WIDGET(battmon->timechargealignment));
+#if defined(__NetBSD__)
+	if (acline || time_remaining == _ACPI_APM_BATT_UNKNOWN)
+		g_snprintf(buffer, sizeof(buffer), "--:--");
+#endif
         g_snprintf(buffer, sizeof(buffer),"%02d:%02d ",time_remaining/60,time_remaining%60);
         gtk_label_set_text(battmon->rtime,buffer);
 
