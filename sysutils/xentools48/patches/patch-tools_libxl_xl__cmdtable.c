$NetBSD: patch-tools_libxl_xl__cmdtable.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/libxl/xl_cmdtable.c.orig	2015-11-03 09:11:18.000000000 +0000
+++ tools/libxl/xl_cmdtable.c
@@ -507,7 +507,7 @@ struct cmd_spec cmd_table[] = {
       "-e                      Do not wait in the background (on <host>) for the death\n"
       "                        of the domain.\n"
       "-N <netbufscript>       Use netbufscript to setup network buffering instead of the\n"
-      "                        default script (/etc/xen/scripts/remus-netbuf-setup).\n"
+      "                        default script (@XENDCONFDIR@/scripts/remus-netbuf-setup).\n"
       "-F                      Enable unsafe configurations [-b|-n|-d flags]. Use this option\n"
       "                        with caution as failover may not work as intended.\n"
       "-b                      Replicate memory checkpoints to /dev/null (blackhole).\n"
