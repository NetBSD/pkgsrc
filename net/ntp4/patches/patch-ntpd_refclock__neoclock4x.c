$NetBSD: patch-ntpd_refclock__neoclock4x.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/refclock_neoclock4x.c.orig	2014-12-29 06:26:52.000000000 +0000
+++ ntpd/refclock_neoclock4x.c
@@ -725,7 +725,8 @@ neoclock4x_control(int unit,
   if(NULL != out)
     {
       char *tt;
-      char tmpbuf[80];
+      /* the 199 here is almost 2x the max string */
+      char tmpbuf[199];
 
       out->kv_list = (struct ctl_var *)0;
       out->type    = REFCLK_NEOCLOCK4X;
@@ -765,14 +766,15 @@ neoclock4x_control(int unit,
         snprintf(tt, 39, "dststatus=\"winter\"");
       else
         snprintf(tt, 39, "dststatus=\"unknown\"");
+      /* the 99 below is greater than 80 the max string */
       tt = add_var(&out->kv_list, 80, RO|DEF);
-      snprintf(tt, 79, "firmware=\"%s\"", up->firmware);
+      snprintf(tt, 99, "firmware=\"%s\"", up->firmware);
       tt = add_var(&out->kv_list, 40, RO|DEF);
       snprintf(tt, 39, "firmwaretag=\"%c\"", up->firmwaretag);
       tt = add_var(&out->kv_list, 80, RO|DEF);
-      snprintf(tt, 79, "driver version=\"%s\"", NEOCLOCK4X_DRIVER_VERSION);
+      snprintf(tt, 99, "driver version=\"%s\"", NEOCLOCK4X_DRIVER_VERSION);
       tt = add_var(&out->kv_list, 80, RO|DEF);
-      snprintf(tt, 79, "serialnumber=\"%s\"", up->serial);
+      snprintf(tt, 99, "serialnumber=\"%s\"", up->serial);
     }
 }
 
