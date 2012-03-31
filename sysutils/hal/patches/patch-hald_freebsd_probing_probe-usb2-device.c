$NetBSD: patch-hald_freebsd_probing_probe-usb2-device.c,v 1.1 2012/03/31 16:06:56 ryoon Exp $

* From FreeBSD ports repository to fix build on FreeBSD 9.0 RELEASE.

--- hald/freebsd/probing/probe-usb2-device.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/probing/probe-usb2-device.c
@@ -147,16 +147,16 @@ main(int argc, char **argv)
 	    speed = 12.0;
 	    bcdspeed = 0x01200;
 	    break;
-	  case LIBUSB20_SPEED_HIGH:
+	  case LIBUSB20_SPEED_VARIABLE:
 	    speed = 480.0;
 	    bcdspeed = 0x48000;
 	    break;
 	  case LIBUSB20_SPEED_SUPER:
-	    speed = 4800.0;
-	    bcdspeed = 0x480000;
+	    speed = 5000.0;
+	    bcdspeed = 0x500000;
 	    break;
 	  default:
-	    ;
+	    break;
 	}
 
       libhal_device_set_property_double(hfp_ctx, hfp_udi, "usb_device.speed",
@@ -169,6 +169,9 @@ main(int argc, char **argv)
           case UD_USB_2_0:
             version = 2.0;
 	    break;
+	  case 0x0250:
+	    version = 2.5;
+	    break;
 	  case UD_USB_3_0:
 	    version = 3.0;
 	    break;
@@ -184,7 +187,7 @@ main(int argc, char **argv)
       libhal_device_set_property_int(hfp_ctx, hfp_udi,
         "usb_device.vendor_id", di.udi_vendorNo, &hfp_error);
       libhal_device_set_property_int(hfp_ctx, hfp_udi,
-        "usb_device.device_revision_bcd", ddesc->bcdUSB, &hfp_error);
+        "usb_device.device_revision_bcd", ddesc->bcdDevice, &hfp_error);
       libhal_device_set_property_string(hfp_ctx, hfp_udi,
         "usb_device.serial", di.udi_serial, &hfp_error);
       libhal_device_set_property_string(hfp_ctx, hfp_udi,
