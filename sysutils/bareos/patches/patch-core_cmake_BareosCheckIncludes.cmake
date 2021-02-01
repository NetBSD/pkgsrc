$NetBSD: patch-core_cmake_BareosCheckIncludes.cmake,v 1.2 2021/02/01 09:08:43 kardel Exp $

	Fix header file checks for NetBSD

--- core/cmake/BareosCheckIncludes.cmake.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/cmake/BareosCheckIncludes.cmake
@@ -38,7 +38,7 @@ check_include_files(sys/bitypes.h HAVE_S
 check_include_files(sys/capability.h HAVE_SYS_CAPABILITY_H)
 check_include_files(sys/ea.h HAVE_SYS_EA_H)
 check_include_files("sys/types.h;sys/extattr.h" HAVE_SYS_EXTATTR_H)
-check_include_files(sys/mtio.h HAVE_SYS_MTIO_H)
+check_include_files("sys/types.h;sys/mtio.h" HAVE_SYS_MTIO_H)
 check_include_files(sys/nvpair.h HAVE_SYS_NVPAIR_H)
 
 check_include_files("sys/types.h;sys/tape.h" HAVE_SYS_TAPE_H)
@@ -88,6 +88,6 @@ check_include_files(
 )
 check_include_files("stdio.h;camlib.h" HAVE_CAMLIB_H)
 check_include_files(cam/scsi/scsi_message.h HAVE_CAM_SCSI_SCSI_MESSAGE_H)
-check_include_files(dev/scsipi/scsipi_all.h HAVE_DEV_SCSIPI_SCSIPI_ALL_H)
+check_include_files("sys/types.h;dev/scsipi/scsipi_all.h" HAVE_DEV_SCSIPI_SCSIPI_ALL_H)
 
 check_include_files(scsi/uscsi_all.h HAVE_USCSI_ALL_H)
