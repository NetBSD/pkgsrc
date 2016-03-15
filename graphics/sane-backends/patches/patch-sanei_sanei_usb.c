$NetBSD: patch-sanei_sanei_usb.c,v 1.1 2016/03/15 09:14:03 martin Exp $

Avoid storing an int (the number of bytes transfered) in the wrong
half of a ssize_t on big endian 64bit platforms.

Reported upstream as:
https://alioth.debian.org/tracker/index.php?func=detail&aid=315337


--- sanei/sanei_usb.c.orig	2014-12-16 14:37:26.000000000 +0100
+++ sanei/sanei_usb.c	2016-03-15 09:12:34.335049822 +0100
@@ -2310,10 +2310,10 @@ sanei_usb_read_bulk (SANE_Int dn, SANE_B
     {
       if (devices[dn].bulk_in_ep)
 	{
-	  int ret;
+	  int ret, rsize;
 	  ret = libusb_bulk_transfer (devices[dn].lu_handle,
 				      devices[dn].bulk_in_ep, buffer,
-				      (int) *size, (int *) &read_size,
+				      (int) *size, &rsize,
 				      libusb_timeout);
 
 	  if (ret < 0)
@@ -2323,6 +2323,10 @@ sanei_usb_read_bulk (SANE_Int dn, SANE_B
 
 	      read_size = -1;
 	    }
+	  else
+	    {
+	      read_size = rsize;
+	    }
 	}
       else
 	{
