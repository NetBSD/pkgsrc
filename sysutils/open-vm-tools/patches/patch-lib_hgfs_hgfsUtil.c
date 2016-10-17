$NetBSD: patch-lib_hgfs_hgfsUtil.c,v 1.1 2016/10/17 20:55:49 ryoon Exp $

* Fix NetBSD/i386 build

--- lib/hgfs/hgfsUtil.c.orig	2016-02-16 20:06:45.000000000 +0000
+++ lib/hgfs/hgfsUtil.c
@@ -109,7 +109,7 @@ int
 HgfsConvertFromNtTimeNsec(struct timespec *unixTime, // OUT: Time in UNIX format
 			  uint64 ntTime) // IN: Time in Windows NT format
 {
-#if !defined(VM_X86_64) && !defined(__arm__)
+#if !defined(VM_X86_64) && !defined(__arm__) && !defined(__NetBSD__)
    uint32 sec;
    uint32 nsec;
 
@@ -134,7 +134,7 @@ HgfsConvertFromNtTimeNsec(struct timespe
       return -1;
    }
 
-#if !defined(VM_X86_64) && !defined(__arm__)
+#if !defined(VM_X86_64) && !defined(__arm__) && !defined(__NetBSD__)
    Div643232(ntTime - UNIX_EPOCH, 10000000, &sec, &nsec);
    unixTime->tv_sec = sec;
    unixTime->tv_nsec = nsec * 100;
