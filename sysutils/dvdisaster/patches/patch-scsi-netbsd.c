$NetBSD: patch-scsi-netbsd.c,v 1.1 2012/02/04 21:57:54 shattered Exp $

--- scsi-netbsd.c.orig	2010-10-27 10:14:46.000000000 +0000
+++ scsi-netbsd.c
@@ -165,6 +165,7 @@ int SendPacket(DeviceHandle *dh, unsigne
 	break;
       case DATA_NONE:
 	sc.flags = 0;
+	break;
       default:
 	Stop("illegal data_mode: %d", data_mode);
    }
