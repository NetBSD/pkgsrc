$NetBSD: patch-src_disk_diskimage__scsicmd.cc,v 1.1 2019/04/11 12:50:30 christos Exp $

Ignore unimplemented disk commands instead of exiting.

--- src/disk/diskimage_scsicmd.cc.orig	2018-12-07 01:29:22.000000000 -0500
+++ src/disk/diskimage_scsicmd.cc	2019-04-11 08:13:01.813050193 -0400
@@ -1145,9 +1145,9 @@
 		break;
 
 	default:
-		fatal("[ UNIMPLEMENTED SCSI command 0x%02x, disk id=%i ]\n",
+		debug("[ UNIMPLEMENTED SCSI command 0x%02x, disk id=%i ]\n",
 		    xferp->cmd[0], id);
-		exit(1);
+		break;
 	}
 	debug(" ]\n");
 
