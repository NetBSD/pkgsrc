$NetBSD: patch-tools_syncml-obex-client.c,v 1.1 2013/03/15 08:25:15 plunky Exp $

--- tools/syncml-obex-client.c.orig	2012-06-20 20:04:00.000000000 +0000
+++ tools/syncml-obex-client.c
@@ -361,14 +361,16 @@ void list_interfaces()
 	if (geteuid() != 0)
 		fprintf(stderr, "Superuser privileges are required to access complete USB information.\n");
 
-	interfaces_number = OBEX_FindInterfaces(handle, &obex_intf);
+	interfaces_number = OBEX_EnumerateInterfaces(handle);
 	printf("Found %d USB OBEX interfaces\n", interfaces_number);
 	
-	for (i = 0; i < interfaces_number; i++)
+	for (i = 0; i < interfaces_number; i++) {
+		obex_intf = OBEX_GetInterfaceByIndex(handle, i);
 		printf("Interface %d:\n\tManufacturer: %s\n\tProduct: %s\n\tInterface description: %s\n", i,
-			obex_intf[i].usb.manufacturer,
-			obex_intf[i].usb.product,
-			obex_intf[i].usb.control_interface);
+			obex_intf->usb.manufacturer,
+			obex_intf->usb.product,
+			obex_intf->usb.control_interface);
+	}
 	
 	printf("Use '-u interface_number' to connect\n");
 	OBEX_Cleanup(handle);
