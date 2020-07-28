$NetBSD: patch-core_src_lib_scsi__lli.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Fix coding - was probably never tested with scsi-crypto flag

--- core/src/lib/scsi_lli.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/lib/scsi_lli.cc
@@ -410,6 +410,7 @@ bool CheckScsiAtEod(int fd) { return fal
 #elif defined(HAVE_NETBSD_OS) || defined(HAVE_OPENBSD_OS)
 
 #if defined(HAVE_NETBSD_OS)
+#include <sys/scsiio.h>
 #include <dev/scsipi/scsipi_all.h>
 #else
 #include <scsi/uscsi_all.h>
@@ -432,7 +433,7 @@ static inline bool do_scsi_cmd_page(int 
 {
   int rc;
   scsireq_t req;
-  SCSI_PAGE_SENSE* sense;
+  SCSI_PAGE_SENSE sense;
   bool opened_device = false;
   bool retval = false;
 
@@ -476,20 +477,18 @@ static inline bool do_scsi_cmd_page(int 
       retval = true;
       break;
     case SCCMD_SENSE:
-      sense = req.sense;
+      memcpy(&sense, &req.sense, sizeof sense < sizeof req.sense ? sizeof sense : sizeof req.sense);
       Emsg3(M_ERROR, 0, _("Sense Key: %0.2X ASC: %0.2X ASCQ: %0.2X\n"),
             LOBYTE(sense.senseKey), sense.addSenseCode, sense.addSenseCodeQual);
       break;
     case SCCMD_TIMEOUT:
       Emsg1(M_ERROR, 0,
             _("SCIOCCOMMAND ioctl on %s returned SCSI command timed out\n"),
-            devicename);
+            device_name);
       break;
     case SCCMD_BUSY:
       Emsg1(M_ERROR, 0, _("SCIOCCOMMAND ioctl on %s returned device is busy\n"),
-            devicename);
-      break;
-    case SCCMD_SENSE:
+            device_name);
       break;
     default:
       Emsg2(M_ERROR, 0,
