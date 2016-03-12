$NetBSD: patch-tun.c,v 1.1 2016/03/12 22:17:51 tnn Exp $

Adapt to current Solaris DDI.

--- tun.c.orig	2011-07-11 02:13:31.000000000 +0000
+++ tun.c
@@ -143,7 +143,12 @@ static	struct dev_ops tun_ops = {
   nodev,		/* devo_reset */
   &tun_cb_ops,		/* devo_cb_ops */
   NULL,			/* devo_bus_ops */
+#ifdef DDI_PM_SUSPEND
   ddi_power		/* devo_power */
+#else
+  NULL,			/* devo_power, deprecated? */
+  ddi_quiesce_not_needed	/* devo_quiesce */
+#endif
 };
 
 static struct modldrv modldrv = {
@@ -229,7 +234,11 @@ static int tundetach(dev_info_t *dev, dd
      ddi_prop_remove_all(dev);
      ddi_remove_minor_node(dev, NULL);
      return (DDI_SUCCESS);
-  } else if( (cmd == DDI_SUSPEND) || (cmd == DDI_PM_SUSPEND) ){
+  } else if( (cmd == DDI_SUSPEND)
+#ifdef DDI_PM_SUSPEND
+ || (cmd == DDI_PM_SUSPEND)
+#endif
+){
      return (DDI_SUCCESS);
   } else
      return (DDI_FAILURE);
