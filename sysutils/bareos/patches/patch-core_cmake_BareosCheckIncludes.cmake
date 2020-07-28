$NetBSD: patch-core_cmake_BareosCheckIncludes.cmake,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Fix header file checks for NetBSD

--- core/cmake/BareosCheckIncludes.cmake.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/cmake/BareosCheckIncludes.cmake
@@ -55,7 +55,7 @@ check_include_files(sys/dl.h HAVE_SYS_DL
 check_include_files(sys/ea.h HAVE_SYS_EA_H)
 check_include_files("sys/types.h;sys/extattr.h" HAVE_SYS_EXTATTR_H)
 check_include_files(sys/ioctl.h HAVE_SYS_IOCTL_H)
-check_include_files(sys/mtio.h HAVE_SYS_MTIO_H)
+check_include_files("sys/types.h;sys/mtio.h" HAVE_SYS_MTIO_H)
 check_include_files(sys/ndir.h HAVE_SYS_NDIR_H)
 check_include_files(sys/nvpair.h HAVE_SYS_NVPAIR_H)
 check_include_files(sys/select.h HAVE_SYS_SELECT_H)
@@ -134,7 +134,7 @@ check_include_files("sys/types.h;sys/scs
                     HAVE_SYS_SCSI_IMPL_USCSI_H)
 check_include_files("stdio.h;camlib.h" HAVE_CAMLIB_H)
 check_include_files(cam/scsi/scsi_message.h HAVE_CAM_SCSI_SCSI_MESSAGE_H)
-check_include_files(dev/scsipi/scsipi_all.h HAVE_DEV_SCSIPI_SCSIPI_ALL_H)
+check_include_files("sys/types.h;dev/scsipi/scsipi_all.h" HAVE_DEV_SCSIPI_SCSIPI_ALL_H)
 
 check_include_files(scsi/uscsi_all.h HAVE_USCSI_ALL_H)
 check_include_files(scsi/uscsi_all.h HAVE_SCSI_USCSI_ALL_H)
