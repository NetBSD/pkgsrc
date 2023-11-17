$NetBSD: patch-spectro_icoms__ux.c,v 1.1 2023/11/17 17:37:48 jakllsch Exp $

Add (some) serial port handling for NetBSD; neutralize serial port probing on NetBSD.

--- spectro/icoms_ux.c.orig	2018-07-09 02:57:13.000000000 +0000
+++ spectro/icoms_ux.c
@@ -242,6 +242,13 @@ int serial_get_paths(icompaths *p, icom_
 			   /* This should match uart & USB devs. */
 				( strncmp (de->d_name, "cua", 3) == 0
 				&& strlen (de->d_name) < 7)
+#elif defined(__NetBSD__)
+			    (   strncmp(de->d_name, "tty", 3) == 0
+			     && isdigit((unsigned char)de->d_name[3]))
+			 || (   strncmp(de->d_name, "ttyU", 4) == 0
+			     && isdigit((unsigned char)de->d_name[4]))
+			 || (   strncmp(de->d_name, "ttyY", 4) == 0
+			     && isdigit((unsigned char)de->d_name[4]))
 #else
 				/* Presumably Linux.. */
 			    (   strncmp(de->d_name, "ttyS", 4) == 0
@@ -261,6 +268,7 @@ int serial_get_paths(icompaths *p, icom_
 			strcpy(dpath, dirn);
 			strcat(dpath, de->d_name);
 
+#if !defined(__NetBSD__)
 			/* See if the (not fast) serial port is real */
 			if (strncmp(de->d_name, "ttyUSB", 6) != 0
 			 && strncmp(de->d_name, "ttyHS", 5) != 0
@@ -300,6 +308,7 @@ int serial_get_paths(icompaths *p, icom_
 				dctype |= icomt_fastserial;
 				dctype |= icomt_btserial;
 			}
+#endif
 
 #ifndef ENABLE_SERIAL
 			if (dctype & icomt_fastserial) {		/* Only add fast ports if !ENABLE_SERIAL */
