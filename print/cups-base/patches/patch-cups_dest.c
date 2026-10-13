$NetBSD: patch-cups_dest.c,v 1.1 2026/10/13 21:18:32 tnn Exp $

https://github.com/OpenPrinting/cups/commit/23a183b63a.patch

--- cups/dest.c.orig	2026-10-05 15:26:07.000000000 +0000
+++ cups/dest.c
@@ -125,6 +125,8 @@ typedef struct _cups_getdata_s
 {
   int		num_dests;		/* Number of destinations */
   cups_dest_t	*dests;			/* Destinations */
+  int		num_local;		/* Number of local cupsd queues */
+  cups_dest_t	*local_dests;		/* Local cupsd queues */
   char		def_name[1024],		/* Default printer name, if any */
 		*def_instance;		/* Default printer instance, if any */
 } _cups_getdata_t;
