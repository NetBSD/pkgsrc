$NetBSD: patch-libscg_scsi-mac-iokit.c,v 1.1 2019/08/18 07:19:47 maya Exp $

- IOkit header location location changes with the macos version.
  IOKit/scsi from macosx Snow Leopard.

--- libscg/scsi-mac-iokit.c.orig	2002-01-29 17:23:22.000000000 +0000
+++ libscg/scsi-mac-iokit.c
@@ -50,12 +50,21 @@ LOCAL	char	_scg_trans_version[] = "scsi-
 #define	MAX_TGT		16
 #define	MAX_LUN		8
 
+#include <AvailabilityMacros.h>
 #include <statdefs.h>
 #include <mach/mach.h>
 #include <Carbon/Carbon.h>
 #include <IOKit/IOKitLib.h>
 #include <IOKit/IOCFPlugIn.h>
+#if MAC_OS_X_VERSION_MAX_ALLOWED >= 1060
+#define COLLISION_VERSION VERSION
+#undef VERSION
+#include <IOKit/scsi/SCSITaskLib.h>
+#define VERSION COLLISION_VERSION
+#undef COLLISION_VERSION
+#else
 #include <IOKit/scsi-commands/SCSITaskLib.h>
+#endif
 #include <mach/mach_error.h>
 
 struct scg_local {
